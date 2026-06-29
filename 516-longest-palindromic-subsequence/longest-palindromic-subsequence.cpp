class Solution {
public:
    int lcs(string s, string t){
        // tabulation approach
        int n=s.size(), m=t.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0; j<=m; j++) dp[0][j]=0; // first row zero kardo
        for(int i=0; i<=n; i++) dp[i][0]=0; // firt col zero kardo for the base case

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }

        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        // brute force: generate all the subsequence and check if it is palindrome and store the length as the maximum one for the palindrome
         //optimised: this can be solved by the similar approach as the lcs
         // we will find the lcs of s and the reverse of s

         string t=s;
         reverse(t.begin(),t.end());
         return lcs(s,t);
    }
};