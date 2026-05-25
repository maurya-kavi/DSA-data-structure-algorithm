class Solution {
public:
    const int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {

            auto [dis, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if(dis > dist[node]) continue;

            for(auto &[adjNode, wt] : adj[node]) {

                long long newDist = dis + wt;

                // Better shortest path found
                if(newDist < dist[adjNode]) {

                    dist[adjNode] = newDist;

                    ways[adjNode] = ways[node];

                    pq.push({newDist, adjNode});
                }

                // Another shortest path found
                else if(newDist == dist[adjNode]) {

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};