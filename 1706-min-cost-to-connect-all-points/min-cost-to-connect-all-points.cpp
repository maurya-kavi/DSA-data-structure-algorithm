class Solution {
public:
// using the prisma algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }

        // start from somewhere
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0}); // wt,node
        vector<bool>vis(n,false);
        int ans=0; //mst
        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();
            
            //pq mein ek node multiple bar present ho sakte hain because wo bahut saare aur node se connected hai , and agar ek bar pq se nikal gya hai toh baki jo same node present hai uska koi use nhi hai
            if(vis[node]) continue;

            vis[node]=true;
            ans+=wt;
            for(auto [ngbrNode, ngbrWt]:adj[node]){
                if(!vis[ngbrNode]){
                    pq.push({ngbrWt,ngbrNode});
                }
            }
        }
        return ans;
    }
};

















