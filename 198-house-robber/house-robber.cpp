class Solution {
public:
int dp[101];
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n, nums);
    }

    int solve(int i, int n, vector<int>&nums){
        if(i>=n) return 0;
if(dp[i]!=-1) return dp[i];
        // if take
        int take=nums[i]+solve(i+2,n, nums);

        int nottake=solve(i+1,n, nums);

        return dp[i]= max(take, nottake);
    }
};