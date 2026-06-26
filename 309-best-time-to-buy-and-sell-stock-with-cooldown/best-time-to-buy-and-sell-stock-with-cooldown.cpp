class Solution {
public:
int dp[5001][2];
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));

        // state if buy 1 then buy change the buy to 0 or keep moving and keep the buy 1 else if buy =0 then sell and change the buy to 1 or keep moving and keep the buy =0;

        return solve(0,1,n,prices);
    }

    int solve(int i, int buy, int n, vector<int>&prices){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            return dp[i][buy]= max(-prices[i]+solve(i+1,0,n,prices), solve(i+1,1,n,prices));
        }else{
            return dp[i][buy]= max(prices[i]+solve(i+2, 1,n,prices), solve(i+1,0,n,prices));
        }
    }
};