/*
  1..9 => 9  1 digit number 
  10..99 => 90 2 digits number
  100..999=> 900  3 digits number, 
  1000..9999=> 9000 4 digits number and so on.
  
  total digits in those 1 digit , 2 digit , 3 digit numbers can be found as 
  1* 9*10^(1-1)=9 total 9 digits from 1 to 9, 
  2*9*10^(2-1)= 180 total digits from 10 to 99, 
  3*9*10^(3-1) = 2700 total digits from 100 to 999 ...
  d * 9 * 10^(d-1) total digits for all numbers with 'd' number of digits.
  
  suppose input is 350,
  as 350 > 9 then target number has more than 1 digit, 
  again 350 > (9+180) then target number has more than 2 digits,
  again 350 < (9+180+2700) then target number can't have more than 3 digits 
  hence target number has 3 digits or something in [100...999] range
  
  k = 350 -(total digits in [1..9] + total digits in [10..99]) = k -(9+180) = 161
  after 99, 3 digits number --> 100 101 102 103 ....so on , 
  161 = 3 * (distance from 99) + reminders
  distance from 99 = 161/3 = 53, reminder 2
  so number is (99 + 53)+1 = 152+1= 153 , 
  [100 101 102 103 104 105. 106 107 ... 152|     153]
  |<----53*3 = 159 total digits----------->|<after that 2 digits more-->| = 161 
  so total digits in the sequence [100 to 152] = 159 , 
  as reminder  is 2 so we have to move   '2' steps more in the sequence
  we shall take next number int the sequence'153' and 2nd digit of 153 is '5'.
  So answer is '5'. 
  
  If input 348, then k = 348 -(9+180) = 159
  in this case reminder is 0
  So answer will be last digit in the sequence [100....152] that is 2. 
*/ 
  
class Solution {
long long tenpowm(int m)
{
    long long res = 1;
    for(int i = 1;i<=m;++i)
        res = res * 10;
    return res;
}
public:
    int findNthDigit(int n) {
        long long res = 1;
    for(int i = 1;i<=m;++i)
        res = res * 10;
    return res;
}
public:
    int findNthDigit(int n) {
       if(n<10)
            return n;

        int digitsInInput = floor(log10(n))+1;
        int b;
        long long base = 0;
        for(b = 1;b<=digitsInInput;++b)
        {
            
            if((long long)n > (base+(b*9*tenpowm(b-1))))
                base = (base+(b*9*tenpowm(b-1))); 
            else
                break;
            
        }
       int digitsInTargetNumber = b;
       long long k = n-base; 
       long long offset = k/(long long)digitsInTargetNumber;
       int r = k%digitsInTargetNumber;
       long long target;
       target = tenpowm(digitsInTargetNumber-1) -1 + offset;
       if(r>0)
            target = target + 1;
        
        int res = 0;
        if(r==0)
            r=digitsInTargetNumber;
        r = digitsInTargetNumber-r;
        while(r>=0)
        {
            res = target%10;
            target /= 10;
            r--;
        }
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().findNthDigit(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
