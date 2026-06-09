class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        // int mx=grid[0][0];
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
        pq.push({grid[0][0],0,0});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[0][0]=true;
        while(!pq.empty()){
            auto [val,r,c]=pq.top();
            pq.pop();
            // mx=max(mx,gird[r][c]);
            if(r==n-1 && c==n-1) return val;
            for(int k=0; k<4; k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr<n && nr>=0 && nc<n && nc>=0 && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    int x=max(val,grid[nr][nc]);
                    pq.push({x,nr,nc});
                }
            }
        }
        return -1;
    }
};