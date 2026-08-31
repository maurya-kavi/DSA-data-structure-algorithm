class Solution {
public:

int dp[201][20005];

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0LL);
        if(sum&1) return false;
        int reqSum=sum/2;
        memset(dp,-1,sizeof(dp));

        return solve(0, nums, reqSum);
    }

    bool solve(int i, vector<int>&nums, int sum){
        if(sum==0){
            return true;
        }
        if(i>=nums.size()) return false;

        if(dp[i][sum]!=-1) return dp[i][sum];

        // take it
        bool take=false, nottake=false;
        if(nums[i]<=sum){
            take=solve(i+1, nums, sum-nums[i]);
        }

        // not take
        nottake=solve(i+1,nums, sum);

        return dp[i][sum]= take | nottake;
    }
};