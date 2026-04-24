class Solution {
public:
    int dp[100005][2][3];
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // int dp[n][2][3];
        // memset(dp,-1,sizeof(dp));
        // return f(0,1,2,prices,n);  // index(0 to n-1), buy(0/1) , cap(0/1/2), prices, n
        // cap=2 means remaining two transection, cap=1 means remaining 1 transection, 0 means remaining no transection.


        //tabulation
        memset(dp,0,sizeof(dp));
        //base case
        for(int buy=0; buy<=1; buy++){
            for(int cap=0; cap<=2; cap++){
                dp[n][buy][cap]=0;
            }
        }

        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy) dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
                    else dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                }
            }
        }
        return max({dp[0][1][0],dp[0][1][1],dp[0][1][2]});
    }
};