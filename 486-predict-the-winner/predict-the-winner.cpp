class Solution {
public:

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] stores the maximum score difference for subarray nums[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: subarrays of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        
        // Build the DP table for subarrays of length 2 up to n
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                
                // Choose left vs choose right
                int chooseLeft = nums[i] - dp[i + 1][j];
                int chooseRight = nums[j] - dp[i][j - 1];
                
                dp[i][j] = max(chooseLeft, chooseRight);
            }
        }
        
        // Player 1 wins if their final score difference is 0 or more
        return dp[0][n - 1] >= 0;
    }
};