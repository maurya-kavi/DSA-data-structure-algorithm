class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

queue<int>q;
vector<bool>vis(n,false);
int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int cntNode=0; int cntEdges=0;
                q.push(i);
            
                vis[i]=true;
                while(!q.empty()){
                    cntNode++;
                    int node=q.front(); q.pop();
                    for(int ngbr:adj[node]){
                        if(!vis[ngbr]){
                            cntEdges++;
                            q.push(ngbr);
                            vis[ngbr]=true;
                        }else cntEdges++;
                    }
                }

                int reqEdges=cntNode*(cntNode-1);
                if(reqEdges==cntEdges) cnt++;
            }
        }

        return cnt;
    }
};