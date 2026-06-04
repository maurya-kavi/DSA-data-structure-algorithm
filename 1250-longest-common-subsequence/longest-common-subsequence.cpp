class Solution {
public:
// recursion , lets memoize it
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,text1,text2,dp);
    }
    int solve(int i,int j, int n, int m , string &text1, string &text2, vector<vector<int>>&dp){
        // base case
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]) return dp[i][j]=1+solve(i+1,j+1,n,m,text1,text2,dp);
        else {
            return dp[i][j]=max(solve(i+1,j,n,m,text1,text2,dp), solve(i,j+1,n,m,text1,text2,dp));
        }
    }
};