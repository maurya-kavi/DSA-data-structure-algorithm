class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<m ; i++){
            int u=times[i][0];
            int v=times[i][1];
            u--, v--;
            int wt=times[i][2];

            adj[u].push_back({v,wt});
        }
        k--;
        // node from 0 to (n-1)
        queue<pair<int,int>>q; // {node,wt}
        q.push({k,0});
        vector<int>dis(n,INT_MAX);
        dis[k]=0;

        // kth node se kon se node pe jane mein uska min time kitna lagega wo dis mein store kardo

        while(!q.empty()){
            auto [node, wt]=q.front();
            q.pop();

            for(auto [ngbrNode, ngbrWt]: adj[node]){
                if(dis[ngbrNode]> (ngbrWt+wt)){
                    dis[ngbrNode]=ngbrWt+wt;
                    q.push({ngbrNode, wt+ngbrWt});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            // if(i=k) continue;
            if(dis[i]==INT_MAX) return -1;
            if(i!=k) ans=max(ans, dis[i]);
        }
        return ans;
    }
};