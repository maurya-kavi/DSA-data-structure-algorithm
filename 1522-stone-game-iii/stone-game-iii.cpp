class Solution {
public:

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // dp[i] stores the max score difference the current player 
        // can achieve starting from index i.
        vector<int> dp(n + 1, -1e9); 
        dp[n] = 0; // Base case: 0 stones left means 0 difference
        
        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            // The player can take 1, 2, or 3 stones
            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                // Current player's score - Opponent's optimal future score
                dp[i] = max(dp[i], take - dp[i + k + 1]); 
            }
        }
        
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }





/* //recursive code giving TLE
    int solve(vector<int>&nums, int i){

        //base cases
        if(i>=n) return 0;

        if(dp[i]!=INT_MIN) return dp[i];

        int take1=nums[i]+min({solve(nums, i+2), solve(nums, i+3), solve(nums, i+4)});

        int take2=INT_MIN, take3=INT_MIN;
        if(i+1 <n) take2=nums[i]+nums[i+1] + min({solve(nums, i+3), solve(nums, i+4), solve(nums, i+5)});

        if(i+2 <n) take3=nums[i]+nums[i+1]+nums[i+2] +min({solve(nums, i+4), solve(nums, i+5), solve(nums, i+6)});

        return dp[i]= max({take1, take2, take3});
    }

*/

};