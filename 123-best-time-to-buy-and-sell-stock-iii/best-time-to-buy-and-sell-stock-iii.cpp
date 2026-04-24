class Solution {
public:
    // int n;
    int dp[100005][2][3];
    int f(int i, int buy, int cap, vector<int>&prices , int n){
        if(i>=n || cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy ){
            return dp[i][buy][cap]= max(-prices[i]+f(i+1,0,cap,prices,n), f(i+1,1,cap,prices,n));
        }
        else{
            return dp[i][buy][cap]= max(prices[i]+f(i+1,1,cap-1,prices ,n), f(i+1,0,cap,prices,n));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // int dp[n][2][3];
        memset(dp,-1,sizeof(dp));
        return f(0,1,2,prices,n);  // index(0 to n-1), buy(0/1) , cap(0/1/2), prices, n
        // cap=2 means remaining two transection, cap=1 means remaining 1 transection, 0 means remaining one transection.
    }
};