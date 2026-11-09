class Solution {
public:
vector<vector<int>>dp;
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans=solve(0,coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
    int solve(int i,vector<int>&coins, int amount){
        if(amount==0){
            return 0;
        }
        if(i==coins.size() || amount<0) return INT_MAX;
        if(dp[i][amount]!=-1){ return dp[i][amount];}
        //if taking the current coin
        int take=INT_MAX;
        if(amount-coins[i]>=0) {
            int x=solve(i,coins, amount-coins[i]);
            if(x!=INT_MAX) take=1+x;
        }
        // if not taking it
        int notake=solve(i+1, coins, amount);

        return dp[i][amount]=min(take,notake);
    }
};