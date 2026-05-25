class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<m;i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];

            adj[u].push_back({v,wt});
        }

        queue<tuple<int,int,int>>q; //node,wt,step
        q.push({src,0,0});
        // vector<bool>vis(n,false);
        // vis[src]=true;
        vector<int>disWt(n,INT_MAX);
        disWt[src]=0;
        while(!q.empty()){
            auto [node, wt, step]=q.front();
            q.pop();

            for(auto [ngbrNode,ngbrWt]:adj[node]){
                // if(!vis[ngbrNode]){
                //     vis[ngbrNode]=true;
                //     q.push({ngbrNode,ngbrWt,step+1});
                // }

                if(disWt[ngbrNode] > (wt+ngbrWt) && (step+1)<=k){
                    disWt[ngbrNode]=wt+ngbrWt;
                    q.push({ngbrNode, wt+ngbrWt, step+1});
                }

                if(ngbrNode==dst){
                    disWt[dst]=min(disWt[dst], wt+ngbrWt);
                }
            }
        }
        if(disWt[dst]==INT_MAX) return -1;
        else return disWt[dst];
    }
};