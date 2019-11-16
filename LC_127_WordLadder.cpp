/**
  *  Problem : 127 https://leetcode.com/problems/word-ladder/
  *  Medium : BFS
  *  @author : Kaushik Biswas
  */
  class Solution {
    int m_dictSize;
    int m_wordLength;
    vector<string> m_dict;
    map<string,vector<int> > m_preproccessedDict;
    
    string replacedString(string str,int index,char c)
    {
        return str.replace(index,1,1,c);
    }
    void addToPreprocDict(string word,int val)
    {
        for(int i = 0;i<m_wordLength;++i)
        {
            m_preproccessedDict[replacedString(word,i,'*')].push_back(val);
        }
    }
    void preproc(vector<string> dict)
    {
        for(int i = 0;i<m_dictSize;++i)
        {
            addToPreprocDict(dict[i],i);
        }

    }
    int bfs(string s, int d)
    {
        vector<bool> v(m_dictSize,false);
        queue<pair<string,int> > q;
        q.push(make_pair(s,1));
    
        int res = 65536;
        while(!q.empty())
        {
            pair<string,int> current  = q.front();
            string curStr = current.first;
            int curLevel = current.second;
            q.pop();
            for(int i = 0;i<m_wordLength;++i)
            {
                string interimString = replacedString(curStr,i,'*');
                if(m_preproccessedDict[interimString].size() == 0)
                {
                    continue;
                }
                else
                {
                
                    for(int j = 0;j<m_preproccessedDict[interimString].size();++j)
                    {
                        int cur = m_preproccessedDict[interimString][j];
                        if(v[cur])
                            continue;
                   
                        if(cur == d)
                        {
                            res = min(res,curLevel+1);
                        }
                        v[cur] = true;
                        q.push(make_pair(m_dict[cur],curLevel+1));
                    }
                
                }
            }
         }
         if(res == 65536) return 0;
         return res;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0) return 0;
        m_dictSize = wordList.size();
        m_wordLength = wordList[0].size();
        m_dict = wordList;
        if(beginWord.compare(endWord) == 0) return 0;
        int dest = 0;
        for(;dest<m_dictSize;++dest)
        {   
            if(endWord.compare(m_dict[dest]) == 0)
                break;
        }
    
        if(dest == m_dict.size()) return 0;
        preproc(m_dict);
        return bfs(beginWord,dest);
    }
};
