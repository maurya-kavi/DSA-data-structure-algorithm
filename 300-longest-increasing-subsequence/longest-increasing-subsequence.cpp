class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>dp(n+1,0);

        // lets say starting from ith and previous is at the 0th then this can be of atleast len =1

        for(int i=1; i<=n; i++) dp[i]=1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<i; j++){
                if(nums[i-1]>nums[j-1]) {
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }




    // int solve(int i, int prev, vector<int>&nums){
    //     if(i==nums.size()) return 0;

    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //     //take 
    //     int take=0;
    //     if(prev==-1 || nums[prev]<nums[i]){
    //         take=1+solve(i+1, i,nums);
    //     }

    //     // not take
    //     int notake=solve(i+1,prev,nums);

    //     return dp[i][prev+1]= max(take,notake);
    // }
};