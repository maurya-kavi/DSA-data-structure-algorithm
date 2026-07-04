class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans=INT_MAX;
int m=roads.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0; i<m; i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
adj[u].push_back({v,wt});
adj[v].push_back({u,wt});
        }

        queue<int>q;
        q.push(1);
        vector<int>vis(n+1);
        vis[1]=true;
        while(!q.empty()){
            auto node=q.front(); q.pop();
            for(auto &[ngbr,wt]:adj[node]){
                if(!vis[ngbr]){
                    ans=min(ans, wt);
                    vis[node]=ngbr;
                    q.push(ngbr);
                }
            }
        }

        return ans;
    }
};