class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //l_b_x -> leftmost bottommost x
        //r_t_x -> rightmost topmost y
        int l_b_x = INT_MAX;
        int l_b_y = INT_MAX;
        int r_t_x = INT_MIN;
        int r_t_y = INT_MIN;
        int numberOfUnitBoxesCovered = 0;
        set<pair<int,int> > s;
        pair<set<pair<int,int> >::iterator,bool> ret;
        for(int i = 0;i<rectangles.size();++i)
        {
            
            int x1 = rectangles[i][0];
            int y1 = rectangles[i][1];
            int x2 = rectangles[i][2];
            int y2 = rectangles[i][3];
            
            //alsways use abs() for co-oridinator arithmetic, else wrong output
            numberOfUnitBoxesCovered += abs(x2-x1)*abs(y2-y1);
            if(x1<l_b_x)
                l_b_x=x1;
            if(y1<l_b_y)
                l_b_y=y1;
            
            if(x2>r_t_x)
                r_t_x=x2;
            if(y2>r_t_y)
                r_t_y=y2;
            
            //x1,y1
            ret = s.insert(make_pair(x1,y1));
            if(ret.second == false) s.erase(ret.first);
            
            //x1,y2
            ret = s.insert(make_pair(x1,y2));
            if(ret.second == false) s.erase(ret.first);
            
            //x2,y1
            ret = s.insert(make_pair(x2,y1));
            if(ret.second == false) s.erase(ret.first);
            
            //x2,y2
            ret = s.insert(make_pair(x2,y2));
            if(ret.second == false) s.erase(ret.first);
        }
        if((s.end() == s.find(make_pair(l_b_x,l_b_y)))
                       || (s.end() == s.find(make_pair(l_b_x,r_t_y)))
                       ||(s.end() == s.find(make_pair(r_t_x,l_b_y)))
                       ||(s.end() == s.find(make_pair(r_t_x,r_t_y)))
                       ||(s.size() != 4))
            return false;
        int numberOfUnitBoxesExpected = abs(r_t_x-l_b_x)*abs(l_b_y-r_t_y);
        if(numberOfUnitBoxesCovered != numberOfUnitBoxesExpected)
            return false;
        return true;
    }
};
