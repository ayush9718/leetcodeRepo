class Solution {
public:
    int n;
    vector<int> prefix;
    vector<int> dp;
    int solve(vector<int> & stones, int index){
        if(index==n-1){
            return prefix[n-1];
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int exclude = solve(stones,index+1);
        int include = prefix[index] - exclude/* in place of exclude there is solve(stones,index+1)*/; 

        return dp[index] = max(include,exclude);
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();

        prefix.assign(n,0);
        prefix[0] = stones[0];

        dp.assign(n+1,-1);

        for(int i =1; i<n;i++){
            prefix[i] = prefix[i-1] + stones[i];
        }

        return solve(stones,1);
    }
};