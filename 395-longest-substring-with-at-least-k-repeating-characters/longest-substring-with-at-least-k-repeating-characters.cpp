class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s,int left, int right , int &k){
        if(right - left+1 <k){
            return 0;
        }

        if(dp[left][right] != -1){
            return dp[left][right];
        }
        vector<int> freq(26, 0);

        for(int i =left; i<=right; i++){
            freq[s[i] - 'a']++;
        }

        for(int i =left; i<=right; i++){

            if(freq[s[i]-'a'] < k){
                int leftans = solve(s,left,i-1,k);
                int rightans = solve(s,i+1,right,k);

                return dp[left][right] =max(leftans,rightans);
            }
        }

        return dp[left][right] = right - left+1;
        
    }
    int longestSubstring(string s, int k) {
        dp.assign(s.length(),vector<int>(s.length()+1,-1));
        return solve(s,0,s.length()-1,k);
    }
};