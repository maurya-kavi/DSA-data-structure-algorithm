class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1){
            if(grid[0][0]==0) return 1;
            else return -1;
        }
        if(grid[0][0]==1) return -1;
        queue<tuple<int,int,int>>q;
        q.push({0,0,1});
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,1,1,1,0,-1,-1,-1};
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[0][0]=true;
        int ans=INT_MAX;
        while(!q.empty()){
            auto [r,c,step]=q.front();
            q.pop();
            for(int i=0; i<8; i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr<n && nr>=0 && nc<n && nc>=0 && grid[nr][nc]==0 && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    q.push({nr,nc,step+1});
                    if(nr==(n-1) && nc==(n-1)) ans=min(ans, step+1);
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};