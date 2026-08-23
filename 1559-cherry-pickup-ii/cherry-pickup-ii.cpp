class Solution {
public: 
    vector<vector<int>> matrix;
    int n,m;
    vector<vector<vector<int>>> dp;
    int solve(int row,int c1,int c2){
        if(row == n){
            return  0;
        }
        if(row>n|| row<0 ||c1>=m || c1<0 || c2>=m || c2<0){
            return  INT_MIN;
        }

        if(dp[row][c1][c2] != -1){
            return dp[row][c1][c2];
        }
        vector<int> dx = {1,1,1};
        vector<int> dy = {-1,0,1};
        
        int ans = INT_MIN;
        int temp = 0;
        if(c1 == c2){
            temp = matrix[row][c1];
        }
        else{
            temp = matrix[row][c1] + matrix[row][c2];
        }


        for(int i =0; i<3; i++){
            for(int j =0; j<3; j++){
                int newrow = row+dx[i];
                int newc1 = c1+dy[i];
                int newc2 = c2+dy[j];

               ans = max(ans, temp + solve(newrow,newc1,newc2));
            }
        }

        return  dp[row][c1][c2] =  ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        matrix = grid;
        n = grid.size();
        m = grid[0].size();
        dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return solve(0,0,m-1);
    }
};