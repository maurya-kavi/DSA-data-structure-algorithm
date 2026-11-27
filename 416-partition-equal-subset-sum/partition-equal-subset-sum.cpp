class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int num:nums) totalSum+=num;
        if(totalSum%2!=0) return false;
        int target=totalSum/2;
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1,-1));
        return solve(nums.size()-1,target, nums, dp);
    }

    bool solve(int idx, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target==0) return true;
        if(idx==0) return nums[idx]==target;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool notake=solve(idx-1, target,nums,dp); // not take the element at index idx and move to next element
        bool take=false;
        if(nums[idx]<=target){
            take=solve(idx-1, target-nums[idx], nums,dp); // taking the element at index idx in the nums
        }

        return dp[idx][target]= notake || take;
    }
};