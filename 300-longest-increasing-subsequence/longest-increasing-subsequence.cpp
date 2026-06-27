class Solution {
public:
int dp[2505][2505];
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return solve(0,-1,nums);
    }

    int solve(int i, int prev, vector<int>&nums){
        if(i==nums.size()) return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        //take 
        int take=0;
        if(prev==-1 || nums[prev]<nums[i]){
            take=1+solve(i+1, i,nums);
        }

        // not take
        int notake=solve(i+1,prev,nums);

        return dp[i][prev+1]= max(take,notake);
    }
};