class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>v(m, vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int x=(j+k);
                int q=i + x/n;
                q%=m;
                int rem=x%n;
                v[q][rem]=grid[i][j];
            }
        }
        return v;
    }
};