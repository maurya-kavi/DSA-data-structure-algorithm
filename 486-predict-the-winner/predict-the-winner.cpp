class Solution {
public:
int n;
int dp[21][21];
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int p1=solve(nums,0,n-1);
        // int p2=accumulate(nums.begin(),nums.end(), 0LL)-p1;

        return p1>=0;
    }
// second approach for doing this problem using memoization , 
    int solve(vector<int>&nums, int i, int j){
        if(i==j) return nums[i];
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int takei=nums[i]-solve(nums,i+1,j);
        int takej=nums[j]-solve(nums,i,j-1);

        return dp[i][j]= max(takei, takej);
    }
    
};