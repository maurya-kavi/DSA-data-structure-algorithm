class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int>dp(n+1,0);
        if(n>=1) dp[1]=nums[0];
        if(n>=2) dp[2]=max(nums[0],nums[1]);
        if(n<=2) return dp[n];

        for(int i=3; i<n; i++){
            dp[i]=max(dp[i-1], nums[i-1]+dp[i-2]);
        }

        vector<int>dp1(n+1, 0);
        if(n>=2) dp1[2]=nums[1];
        if(n>=3) dp1[3]=max(nums[1],nums[2]);
        for(int i=4; i<=n; i++){
            dp1[i]=max(dp1[i-1], dp1[i-2]+nums[i-1]);
        }
        return max(dp[n-1], dp1[n]);
    }
};