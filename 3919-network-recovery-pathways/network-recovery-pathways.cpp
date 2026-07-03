class Solution {
public:
    using ll = long long;
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        
        ll max_wt = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            if (online[u] && online[v]) {
                adj[u].push_back({v, wt});
                
                max_wt = max(max_wt, (ll)wt);
            }
        }
        
   
        auto canReach = [&](ll min_required_wt) {
            vector<ll> dist(n, LLONG_MAX);
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
            
            dist[0] = 0;
            pq.push({0, 0});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                
                if (d > dist[u]) continue;
                if (u == n - 1) return dist[u] <= k;
                
                for (auto& [v, wt] : adj[u]) {
                    if (wt >= min_required_wt) {
                        if (dist[u] + wt < dist[v]) {
                            dist[v] = dist[u] + wt;
                            pq.push({dist[v], v});
                        }
                    }
                }
            }
            return dist[n - 1] <= k;
        };
        
        ll low = 0, high = max_wt, ans = -1;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            if (canReach(mid)) {
                ans = mid;   
                low = mid + 1;   
            } else {
                high = mid - 1;  
            }
        }
        
        return ans;
    }
};


// previously we are storing all the possible state in the queue that leads to the MLE , but here we are look for the answer if possible then look for the lareger anser using binary search for the answer