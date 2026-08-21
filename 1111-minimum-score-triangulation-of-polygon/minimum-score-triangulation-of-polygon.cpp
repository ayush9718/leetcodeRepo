class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& values, int i , int j){
        if(j-i+1 <3){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        long long ans = INT_MAX ;

        for(int k = i+1; k<j; k++){
            long long temp = values[i]*values[k]*values[j] + 
                                solve(values,i,k) + solve(values,k,j);

            ans = min(ans,temp);
        }

        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        n = values.size();

        dp.assign(n+1,vector<int>(n+1,-1));

        return solve(values,0,n-1);
    }
};