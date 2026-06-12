
class Solution {
    int LOG;
    vector<int> depth;
    vector<vector<int>> up;
    int MOD = 1e9 + 7;

    void buildIteratively(int root, int n, const vector<vector<int>>& adj) {
        queue<int> q;
        vector<bool> vis(n, false);
        
        // Ground zero
        q.push(root);
        vis[root] = true;
        depth[root] = 0;
        up[root][0] = -1; // The root bows to no one
        
        // Phase 1: The Breadth-First Expansion (Laying the Foundation)
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    depth[v] = depth[u] + 1;
                    up[v][0] = u; // Record the immediate parent
                    q.push(v);
                }
            }
        }
        
        // Phase 2: Dynamic Programming Tabulation (Forging the Ancestor Matrix)
        // We calculate column by column (powers of 2) for every single node.
        for (int i = 1; i < LOG; i++) {
            for (int node = 0; node < n; node++) {
                if (up[node][i - 1] != -1) {
                    // The core DP transition
                    up[node][i] = up[up[node][i - 1]][i - 1];
                } else {
                    up[node][i] = -1; // The void remains the void
                }
            }
        }
    }

    // Phase 3: The Logarithmic Leap (Unchanged)
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int i = LOG - 1; i >= 0; i--) {
            if ((diff >> i) & 1) u = up[u][i];
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size() +1;
        LOG = ceil(log2(n)) + 1;
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, -1));

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0] - 1; 
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Execute the purely iterative build
        buildIteratively(0, n, adj);

        vector<int> answers;
        answers.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0] - 1;
            int v = q[1] - 1;

            int lca = getLCA(u, v);
            int k = depth[u] + depth[v] - 2 * depth[lca];

            if (k == 0) answers.push_back(0);
            else answers.push_back(power(2, k - 1));
        }

        return answers;
    }
};