class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n+2,0);
        vector<int>dp2(n+2,0);



        // 0 to n-2
        for(int i=n-2; i>=0; i--){
            dp1[i]=max(nums[i]+dp1[i+2], dp1[i+1]);
        }

        // 1 to n-1
        for(int i=n-1; i>=1; i--){
            dp2[i]=max(nums[i]+dp2[i+2], dp2[i+1]);
        }

        return max(dp1[0], dp2[1]);
    }

//     int solve(int i, int n, vector<int>&nums,vector<int>&dp){
//         if(i>=n) return 0;
// if(dp[i]!=-1) return dp[i];

//         int take=nums[i]+solve(i+2,n,nums,dp);
//         int nottake=solve(i+1,n,nums,dp);

//         return dp[i]= max(take, nottake);
//     }
};