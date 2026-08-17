class Solution {
public:

    int solve(string &s,int left, int right , int &k){
        if(right - left+1 <k){
            return 0;
        }
        vector<int> freq(26, 0);

        for(int i =left; i<=right; i++){
            freq[s[i] - 'a']++;
        }

        for(int i =left; i<=right; i++){

            if(freq[s[i]-'a'] < k){
                int leftans = solve(s,left,i-1,k);
                int rightans = solve(s,i+1,right,k);

                return max(leftans,rightans);
            }
        }

        return right - left+1;
        
    }
    int longestSubstring(string s, int k) {
       
        return solve(s,0,s.length()-1,k);
    }
};