class Solution {
public:
int n,m;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
    void dfs(int r, int c, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        vis[r][c]=true;
        for(int i=0; i<4; i++){
            int nr=dr[i]+r;
            int nc=dc[i]+c;
            if(nr<n && nr>=0 && nc<m && nc>=0 && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // jo jo land cell boundary se connected hai and usse jo bhi cell directly or indeirectly connected hai can be walk off the boundary of the grid , and other land cell that nowhere connected directly or indirectly with boundary land cell can't be walked off boundary of the grid

        n=grid.size();
        m=grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m , false));

        for(int j=0; j<m; j++){
            //first row
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,grid,vis);
            }

            // last row
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfs(n-1,j,grid,vis);
            }
        }

        for(int i=0; i<n; i++){
            // first col
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }
            //lasst col
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis);
            }
        }

        // now the 1 in the grid that is not visiteed are cells that can't be walked off to boundary

        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1) cnt++;
            }
        }
        return cnt;

    }
};