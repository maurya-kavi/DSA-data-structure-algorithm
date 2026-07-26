class Solution {
public:
    unordered_set<string> st;
    unordered_map<int, vector<string>> dp;
    int n;

    vector<string> solve(string &s, int ind) {
        if (dp.count(ind)) return dp[ind];

        vector<string> res;

        if (ind == n) {
            res.push_back("");
            return dp[ind] = res;
        }

        string t;

        for (int i = ind; i < n; i++) {
            t += s[i];

            if (!st.count(t)) continue;

            vector<string> nxt = solve(s, i + 1);

            for (auto &x : nxt) {
                if (x.empty())
                    res.push_back(t);
                else
                    res.push_back(t + " " + x);
            }
        }

        return dp[ind] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for (auto &x : wordDict) st.insert(x);
        return solve(s, 0);
    }
};