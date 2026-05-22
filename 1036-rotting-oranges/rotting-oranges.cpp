class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(); //rows
        int m=grid[0].size(); //  col

        int ans=0;
        queue<tuple<int,int,int>>q;
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2) {
                    q.push({i,j,0});
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto [r,c,t]=q.front();
            ans=t;
            q.pop();
            for(int i=0; i<4; i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr<n && nr>=0 && nc<m && nc>=0 && grid[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    q.push({nr,nc,t+1});
                }
            }
        }
        
        // check if any left to  be rotten
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return ans;
    }
};