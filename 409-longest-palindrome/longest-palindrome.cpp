class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        for(auto ch: s){
            freq[ch]++;
        }

        int oddcount = 0;
        int evencount = 0;

        for(auto f: freq){
            if(f.second%2 == 0){
                evencount += f.second;
            }
            else{
                if(f.second >1){
                    evencount+= f.second-1;
                }
                oddcount+=1;
            }
        }
        oddcount = min(oddcount,1);

        return evencount+oddcount;

    }
};