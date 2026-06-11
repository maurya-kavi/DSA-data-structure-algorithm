class Solution {
    int power(long long base, int exp) {
        int mod = 1e9 + 7;
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        // first find the number of edges to reach from 1 to n
        int n=edges.size();
        n++;
        vector<vector<int>>adj(n);
        for(int i=0; i<n-1; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mxdepth=0;
        queue<pair<int,int>>q;
        vector<bool>vis(n,false);
        vis[0]=true;
        q.push({0,0});
        while(!q.empty()){
            auto [node,step] = q.front();
            q.pop();
            mxdepth=max(mxdepth,step);
            for(auto ngbr:adj[node]){
                if(!vis[ngbr]){
                    vis[ngbr]=true;
                    q.push({ngbr,step+1});
                }
            }
        }

        // now we have the no of egdes for the maximum depth , give each edges 1 or 2 wt such that total sum is odd, so how many such combination can be formed   
        if(mxdepth==0) return 0;

        return power(2,mxdepth-1);
    }
};