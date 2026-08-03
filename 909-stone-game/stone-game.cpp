class Solution {
public:
int n;
int dp[501][501];
    bool stoneGame(vector<int>& piles) {
        n=piles.size();
memset(dp,-1, sizeof(dp));
        int alice=solve(piles,0,n-1);
        int bob=accumulate(piles.begin(),piles.end(), 0LL)-alice;
        return alice>bob;

    }

    int solve(vector<int>&nums, int i, int j){
        if(i==j) return nums[i];
        if(i>j) return 0;
if(dp[i][j]!=-1) return dp[i][j];
        int takei=nums[i]+min(solve(nums, i+2, j), solve(nums, i+1, j-1));
        int takej=nums[j]+min(solve(nums, i+1, j-1), solve(nums, i, j-2)); 

        return dp[i][j]=max(takei,takej);
    }
};