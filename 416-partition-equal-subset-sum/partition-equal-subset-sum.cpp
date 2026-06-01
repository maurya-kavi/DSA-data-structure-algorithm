class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totSum=accumulate(nums.begin(), nums.end(), 0LL);
        int target=totSum/2;
        if(totSum%2!=0) return false;

        // now search an subset whose sum is equal to the target
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int i=target; i>=num; i--){
                if(dp[i-num]==true){
                    dp[i]=true;
                }
            }
        }
        return dp[target];
    }
};