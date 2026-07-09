class Solution {
public:
using ll=long long;
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    vector<int> g(n, 0);
        int component_id = 0;

// isolate island
        for (int i = 1; i < n; ++i) {
            // If the consecutive gap exceeds maxDiff, a new component is born
            if (nums[i] - nums[i - 1] > maxDiff) {
                component_id++;
            }
            g[i] = component_id;
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            ans.push_back(g[u] == g[v]); // agar dono ka id same hai
        }

        return ans;
    }
};