class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            dp[i]=max(nums[i]+dp[i+2], dp[i+1]);
        }
        return dp[0];
    }

//     int solve(int i, int n, vector<int>&nums){
//         if(i>=n) return 0;
// if(dp[i]!=-1) return dp[i];
//         // if take
//         int take=nums[i]+solve(i+2,n, nums);

//         int nottake=solve(i+1,n, nums);

//         return dp[i]= max(take, nottake);
//     }
};