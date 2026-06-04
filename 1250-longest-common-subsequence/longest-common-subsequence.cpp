class Solution {
public:
// tabulation
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i]==text2[j]) dp[i][j]=1+dp[i+1][j+1];
                else {
                    dp[i][j]=max(dp[i+1][j] , dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }


    // // initialize last col ----- these way of initialization is not competely correct, so take the dp of 1 more extra length ,
        // for(int i=n-1; i>=0; i--){
        //     if(text1[i]==text2[m-1]) dp[i][m-1]=1;
        // }
        // // initialize last row
        // for(int j=m-1; j>=0; j--){
        //     if(text1[n-1]==text2[j]) dp[n-1][j]=1;
        // }


        // recursion wih memoization approach
    // int solve(int i,int j, int n, int m , string &text1, string &text2, vector<vector<int>>&dp){
    //     // base case
    //     if(i==n || j==m) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(text1[i]==text2[j]) return dp[i][j]=1+solve(i+1,j+1,n,m,text1,text2,dp);
    //     else {
    //         return dp[i][j]=max(solve(i+1,j,n,m,text1,text2,dp), solve(i,j+1,n,m,text1,text2,dp));
    //     }
    // }


};