class Solution {
public:
    int n, m;
    string target;
    string solve(vector<string>& board,int row, int col,int i){
        if(target.length() == i){
            return "";
        }   
        if(row>=n || row <0 || col>=m || col<0 || board[row][col] == '@'){
            return "";
        }


        char need = target[i];

        if(board[row][col] == need){
            return "!" + solve(board,row,col,i+1);
        }

        int newrow = (need-'a')/5;
        int newcol = (need-'a')%5;

        string ans = "";
        
        if(newcol < col){
             ans = "L" + solve(board,row,col-1,i);
        }
        else if(newrow < row){
             ans = "U" + solve(board,row-1,col,i);
        }
        else if(newrow > row){
             ans = "D" + solve(board,row+1,col,i);
        }
        else{
             ans = "R" + solve(board,row,col+1,i);
        }

        return ans;
    }

    string alphabetBoardPath(string target) {
        vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy" , "z@@@@"};

        this->target = target;

        n = board.size();
        m = board[0].size();


        return solve(board,0, 0, 0);

    }
};