class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(), m=grid[0].size();

        // priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;

        priority_queue<tuple<int,int,int>>pq;

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        pq.push({health-grid[0][0],0,0});
        vis[0][0]=true;
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

        while(!pq.empty()){
            auto [h,r,c]=pq.top();
            pq.pop();
            if(h>0 && r==(n-1) && c==(m-1)) return true;

            if(h==0) return false;

            for(int k=0; k<4; k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    pq.push({h-grid[nr][nc], nr,nc});
                }
            }
        }
return false;
    }
};