class Solution {
public:
    int shortest_sub(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        //base cases
        
        if(target==0){
            return 0;
        }
        if(ind<0){
            return INT_MAX;
        }

        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }

        int notTake=shortest_sub(ind-1,target,coins,dp);

        int take=INT_MAX;
        if(coins[ind]<=target){
            int result_from_take=shortest_sub(ind,target-coins[ind],coins,dp);

            if(result_from_take!=INT_MAX){
                take=1+result_from_take;
            }
        }

        return dp[ind][target]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result= shortest_sub(n-1,amount,coins,dp);
        if(result==INT_MAX) return -1;

        return result;
    }
};