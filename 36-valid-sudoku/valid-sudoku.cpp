class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //here we have to only look for the filled cells
        int row = board.size();
        int col = board[0].size();
        //checking all the col
        for(int i=0; i<col; i++){
            unordered_map<char,int> mpp;


            for(int j=0; j<row; j++){
                if(board[j][i]!='.'){
                    mpp[board[j][i]]++;
                    if(mpp[board[j][i]]>1){
                        return false;
                    }
                }
            }
        }

        // check for all row
        for(int i=0; i<row; i++){
            unordered_map<char,int> mpp;
            for(int j=0; j<col; j++){
                if(board[i][j]!='.'){
                    mpp[board[i][j]]++;
                    if(mpp[board[i][j]]>1){
                        return false;
                    }
                }
            }
        }

        // ckeck for unique digit in all 3*3
        for(int blockrow=0; blockrow<3; blockrow++){
            for(int blockcol=0; blockcol<3; blockcol++){
                unordered_map<char, int> mpp;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        char c = board[blockrow*3 + i][blockcol*3 + j];
                        if(c!='.'){
                            mpp[c]++;
                            if(mpp[c]>1){
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};