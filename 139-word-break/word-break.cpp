class Solution {
public:
    bool dfs(int start, string& s, unordered_set<string>& dict, vector<int>& dp) {
        if (start == s.length()) return true;
        if (dp[start] != -1) return dp[start];

        for (int end = start + 1; end <= s.length(); ++end) {
            if (dict.count(s.substr(start, end - start)) &&
                dfs(end, s, dict, dp)) {
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return dfs(0, s, dict, dp);
    }
};