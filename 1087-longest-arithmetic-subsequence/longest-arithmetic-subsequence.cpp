class Solution {
public:

// recursion + memo
int dp[1001][1005];
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d=nums[j]-nums[i];
                if(dp[i][d+500]!=-1) {
                    res=max(res,dp[i][d+500]);
                    continue;
                }
                res=max(res, 2+solve(i,d,nums));
            }
        }

        return res;
    }

    int solve(int i, int diff, vector<int>&nums){
        if(i<0) return 0;
        if(dp[i][diff+500]!=-1) return dp[i][diff+500];
        int ans=0;
        for(int j=i-1; j>=0; j--){
            if(nums[i]-nums[j]==diff)  ans=max(ans, 1+solve(j,diff,nums));
        }

        return dp[i][diff+500] =ans;
    }
};