class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        
        // Find the absolute minimum price for the "filler" phase, -- jab free copies wala nhi buy kiya jaa sakta hai free copies wala req pura ho jayega then minimum item wala buy kiya jayega

        int min_price = 1e9;
        for (const auto& item : items) {
            min_price = min(min_price, item[1]);
        }

        // Precalculate the value (1 bought + X freebies) for activating each item type
        vector<int> value(n, 0);
        for (int i = 0; i < n; i++) {
            int free_count = 0;
            for (int j = 0; j < n; j++) {
                // j != i AND factor_i divides factor_j
                if (i != j && items[j][0] % items[i][0] == 0) {
                    free_count++;
                }
            }
            value[i] = 1 + free_count; // The actual weight/payload of choosing this item once
        }

        //  0/1 Knapsack DP
        // dp[w] = max items obtained by spending exactly 'w' on unique item activations
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int w = items[i][1]; // Cost of the item
            int v = value[i];    // Payload of the item
            
            // Traverse backward to prevent picking the same item twice (0/1 Knapsack constraint)
            for (int j = budget; j >= w; j--) {
                if (dp[j - w] != -1) {
                    dp[j] = max(dp[j], dp[j - w] + v);
                }
            }
        }

        // Squeeze the leftovers
        int max_total = 0;
        for (int w = 0; w <= budget; w++) {
            if (dp[w] != -1) {
                // If we spent 'w', we dump the remaining budget into the cheapest item
                int extra_copies = (budget - w) / min_price;
                max_total = max(max_total, dp[w] + extra_copies);
            }
        }

        return max_total;
    }
};