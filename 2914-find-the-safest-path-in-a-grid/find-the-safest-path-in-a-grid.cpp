class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) v.push_back({i,j});
            }
        }
if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

if(v.size()==0) return (2*n);

        int mnDisforStart=INT_MAX;
        for(int i=0; i<v.size(); i++){
            mnDisforStart=min(mnDisforStart, v[i].first+v[i].second);
        }

priority_queue<tuple<int,int,int>>q;
        // queue<tuple<int,int,int>>q;
        q.push({mnDisforStart,0,0});
int ans=INT_MIN;

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};


vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
queue<pair<int,int>>disQ;
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(grid[i][j]==1){
            dist[i][j]=0;
            disQ.push({i,j});
        }
    }
}

while(!disQ.empty()){
    auto [r,c]=disQ.front();
    disQ.pop();
    for(int k=0; k<4; k++){
        int nr=r+dr[k];
        int nc=c+dc[k];

        if(nr<n && nr>=0 && nc<n && nc>=0 && dist[nr][nc]==INT_MAX){
            dist[nr][nc]=1+dist[r][c];
            disQ.push({nr,nc});
        }
    }
}

vector<vector<bool>>vis(n, vector<bool>(n,false));
vis[0][0]=true;

        while(!q.empty()){
            auto [mn,r,c]=q.top();
            // grid[r][c]=-1;
            q.pop();

            if(mn==0) return 0;

            if(r==n-1 && c==n-1){
                ans=max(ans,mn);
                return ans;
            }

            for(int k=0; k<4; k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    if(!vis[nr][nc]){
                        vis[nr][nc]=true;
                    int mndis=dist[nr][nc];
                    int x=min(mndis,mn);
                    q.push({x,nr,nc});
                    }
                }
            }
        }

        return ans;
    }
};