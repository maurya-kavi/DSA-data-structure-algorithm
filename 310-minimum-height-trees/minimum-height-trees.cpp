class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

// n =1 or 2?
if(n==1) return {0};
if(n==2) return {0,1};


        int m=edges.size();
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        for(int i=0; i<m; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            indeg[u]++;
            indeg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

queue<int>q;
vector<bool>vis(n,false);
        for(int i=0; i<n; i++){
            if(indeg[i]==1){ q.push(i); vis[i]=true;}
        }
vector<int>ans;
        while(!q.empty()){
            int s=q.size();
            vector<int>a;
            for(int i=0; i<s; i++){
                int node=q.front();
                q.pop();
                a.push_back(node);
                for(auto ngbr:adj[node]){
                    if(!vis[ngbr]){
                        indeg[ngbr]--;
                        if(indeg[ngbr]==1){
                            q.push(ngbr);
                            vis[ngbr]=true;
                        }
                    }
                }
            }
            ans=a;
        }
        return ans;
    }
};