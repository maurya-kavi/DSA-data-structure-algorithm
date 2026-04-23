class Solution {
public:
//tabulation + space optimization 
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // dp[0]=1;
        // dp[1]=1;
        if(n==1) return n;
        int prev=1;
        int prev2=1;
        int curri=0;
        for(int i=2; i<=n; i++){
            curri=prev+prev2;
            prev2=prev;
            prev=curri;
            
        }
        return curri;
    }
};