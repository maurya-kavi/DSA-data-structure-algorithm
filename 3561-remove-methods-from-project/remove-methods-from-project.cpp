class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < (int)invocations.size(); i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }

        //  Find all suspicious methods using BFS
        queue<int> q;
        vector<bool> is_suspicious(n, false);
        
        q.push(k);
        is_suspicious[k] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int ngbr : adj[node]) {
                if (!is_suspicious[ngbr]) {
                    is_suspicious[ngbr] = true;
                    q.push(ngbr);
                }
            }
        }

        // Check if any non-suspicious method calls a suspicious method
        bool can_remove = true;
        for (int i = 0; i < (int)invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            // If u is safe but v is suspicious, we cannot remove the suspicious group
            if (!is_suspicious[u] && is_suspicious[v]) {
                can_remove = false;
                break;
            }
        }

        vector<int> ans;
        if (!can_remove) {
            // Return all methods
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        } else {
            // Return only the non-suspicious methods
            for (int i = 0; i < n; i++) {
                if (!is_suspicious[i]) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};