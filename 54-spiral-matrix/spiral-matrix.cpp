class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // row start , row end , col start , col end
        int rs=0, re=matrix.size()-1, cs=0, ce =matrix[0].size()-1;
        vector<int> ans;
        while(rs<=re && cs <= ce){
            // top row ( cs to ce)
            for(int i=cs; i<=ce; i++){
                ans.push_back(matrix[rs][i]);
                
            }
            rs++;

            //rightmost col (rs to re)
            for(int i=rs;i<=re;i++){
                ans.push_back(matrix[i][ce]);
                
            }
            ce--;

            //bottom row ( ce to cs)
            //check still in the matrix uncovered
            if(rs<=re){
                for(int i=ce; i>=cs;i--){
                    ans.push_back(matrix[re][i]);
                    
                }
                re--;
            }

            //leftmost col (re to rs);
            // check still uncovered in the matrix
            if(cs<=ce){
                for(int i=re; i>=rs; i--){
                    ans.push_back(matrix[i][cs]);
                    
                }
                cs++;
            }
        } 
        return ans;
    }
};