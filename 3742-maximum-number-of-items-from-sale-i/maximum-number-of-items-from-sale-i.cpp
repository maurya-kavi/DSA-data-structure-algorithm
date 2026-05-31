class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> bonus(n, 0);

        for (int i = 0; i < n; i++) {
            int fi = items[i][0];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (items[j][0] % fi == 0)
                    bonus[i]++;
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            int g = bonus[i];

            vector<int> ndp = dp;

            for (int r = 0; r < p; r++) {
                long long best = -(long long)1e18;

                int m = 0;
                for (int idx = r; idx <= budget; idx += p, m++) {

                    if (best != -(long long)1e18) {
                        ndp[idx] = max(
                            ndp[idx],
                            (int)(m + g + best)
                        );
                    }

                    best = max(best, (long long)dp[idx] - m);
                }
            }

            dp.swap(ndp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};