class Solution {
public:
// tabulation 
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+1,0);
        dp[1]=nums[0];
        dp[2]=max(nums[0],nums[1]);
        for(int i=3; i<=n; i++){
            dp[i]=max(dp[i-1], nums[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};