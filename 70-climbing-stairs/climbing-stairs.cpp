class Solution {
public:

int dp[46];
    int rec(int n){
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=rec(n-1)+rec(n-2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        dp[1]=1;
        dp[2]=2;
        rec(n);
        return dp[n];
    }
};