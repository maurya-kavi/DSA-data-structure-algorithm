class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum = 0;
        for(int num : nums) total_sum += num;
        
        // If the target is physically impossible to reach, return 0
        if(abs(target) > total_sum) return 0;
        
        // The DP table size needs to accommodate up to 2 * total_sum
        // Initialize with -1 to clearly indicate "uncalculated" states
        vector<vector<int>> dp(n, vector<int>(2 * total_sum + 1, -1));
        
        // We pass the current_sum (starting at 0) instead of shrinking the target.
        // This is much easier to track with the offset.
        return rec(0, 0, nums, target, total_sum, dp);
    }
    
    int rec(int ind, int current_sum, vector<int>& nums, int target, int total_sum, vector<vector<int>>& dp) {
        // Base Case: If we processed all elements
        if (ind == nums.size()) {
            return current_sum == target ? 1 : 0;
        }
        
        // Memoization Check: Apply the offset to the current_sum
        // This guarantees the index is always >= 0
        if (dp[ind][current_sum + total_sum] != -1) {
            return dp[ind][current_sum + total_sum];
        }
        
        // Taking with +
        int sum1 = rec(ind + 1, current_sum + nums[ind], nums, target, total_sum, dp);
        
        // Taking with -
        int sum2 = rec(ind + 1, current_sum - nums[ind], nums, target, total_sum, dp);

        // Store the result using the offset and return
        return dp[ind][current_sum + total_sum] = sum1 + sum2;
    }
};