class Solution {
public:
// optimised using  kadane algo
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int x : nums) {
            // Kadane for max subarray
            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);

            // Kadane for min subarray
            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);

            totalSum += x;
        }

        // If all elements are negative
        if (maxSum < 0) return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};