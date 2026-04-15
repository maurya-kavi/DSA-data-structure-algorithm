class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        rec(board,n,0,0);
    }

    bool rec(vector<vector<char>>&board, int n,int i, int j){
        if(i==9) {
            return true;
        }
        if(j==9){
            return rec(board,n,i+1,0);
        }

                if(board[i][j]=='.'){
                    //try with all the char from 0 to 9
                    for(int k=1; k<=9; k++){
                        char ch=k+'0';
                        if(isSafe(board,n,ch,i,j)){
                            board[i][j]=ch;
                            if(rec(board,n,i,j+1)) return true;
                            board[i][j]='.';
                        }
                    }
                }else return rec(board,n,i,j+1);
        return false;
        
    }

    bool isSafe(vector<vector<char>>&board, int n,char ch, int i,int j){

        // check in the row
        for(int ii=0; ii<9; ii++){
            if(board[i][ii]==ch) return false;
        }

        //for in the col
        for(int ii=0; ii<9; ii++){
            if(board[ii][j]==ch) return false;
        }

        // check in the 3*3 matrix
        int x=i/3, y=j/3;
        x*=3,y*=3;
        for(int jj=y; jj<y+3; jj++){
            for(int ii=0; ii<3; ii++){
                int p=ii+x;
                if(board[p][jj]==ch) return false;
            }
        }

        return true;
    }
};