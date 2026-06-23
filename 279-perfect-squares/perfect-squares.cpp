class Solution {
public:
#define ll long long
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (isPerfectSquare(i)) {
                dp[i] = 1;
                continue;
            }
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j < i; j++) {
                dp[i] = min(dp[i], dp[j] + dp[i - j]);
            }
        }
        return dp[n];
    }
    bool isPerfectSquare(ll x) {
        if (x >= 0) {
            ll sr = sqrt(x);
            return (sr * sr == x);
        }
        return false;
    }
};