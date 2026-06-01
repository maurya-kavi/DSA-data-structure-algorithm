class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totSum=accumulate(nums.begin(), nums.end(), 0LL);
        int target=totSum/2;
        if(totSum%2!=0) return false;

        dp.assign(n,vector<int>(target+1,-1));
        // now search an subset whose sum is equal to the target
        return (rec(nums,target,0,n));
    }

    bool rec(vector<int>&nums, int target, int i, int n){
        if(target==0) return true;
        if(i==n) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        // if notaken
        bool notaken=rec(nums, target, i+1,n);
        //if taken
        bool taken=false;
        if(target>=nums[i]) taken=rec(nums, target-nums[i], i+1, n);

        return dp[i][target]=notaken || taken;
    }
};