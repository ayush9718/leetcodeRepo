class Solution {
public:
    long long totalsum;
    int n; 

    vector<vector<int>> dp;

    int solve(vector<int>& stones,int i, int target) {
        if(i>=n || target==0) return 0;

        if(dp[i][target] != -1){
            return dp[i][target];
        }
        // exclude
        int exclude = solve(stones,i+1,target);

        // include
        int include = 0;
        if(stones[i] <= target) {
            include = stones[i] +solve(stones,i+1,target - stones[i]);
        }

        return dp[i][target] = max(include,exclude);
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        totalsum =0;
        for(int i =0; i<n; i++){
            totalsum+= stones[i];
        }
        int target = totalsum/2;

        dp.assign(n+1,vector<int>(target+1,-1));
        int ans = solve(stones,0,target);
        ans = totalsum - ans*2;
        return ans;
    }
};