class Solution {
public:
    vector<vector<string>> ans;
    int N;

    unordered_map<int, bool> colm;
    unordered_map<int, bool> diag;
    unordered_map<int, bool> antid;

    void solve(vector<string>& board, int row){
        if(row == N){
            ans.push_back(board);
            return ;
        }

        for(int col = 0; col<N; col++){
            int d = row+col;
            int ad = row - col;

            if(colm[col] == false && diag[d] == false && antid[ad] == false){
                colm[col] = true;
                diag[d] = true;
                antid[ad] = true;

                board[row][col] = 'Q';
                solve(board, row+1);

                board[row][col] = '.';
                colm[col] = false;
                diag[d] = false;
                antid[ad] = false;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n,string(n,'.'));
        solve(board,0);

        return ans;
    }
};