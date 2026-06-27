class Solution {
public:

// tabulation

    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>dp(n,vector<int>(1001,0));
int ans=0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int diff=nums[i]-nums[j];
                dp[i][diff+500] = dp[j][diff+500] > 0 ? 1+dp[j][diff+500] : 2;
                ans=max(ans, dp[i][diff+500]);
            }
        }

        return ans;
    }
};