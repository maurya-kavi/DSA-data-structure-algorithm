class Solution {
public:
    int f(int i,int j, string &s,string &t,vector<vector<int>>&dp){
        if(i<0) return j+1; // first word i exhausted so insert the remaing element of word2 in word 1
        if(j<0) return i+1; // if the second word is exhausted so delete the remaining chars of word1

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) {
            return dp[i][j]= f(i-1,j-1,s,t,dp);
        }
        else {
            // 1+ min(delete,insert,replace)
            return dp[i][j]= 1+min(f(i-1,j,s,t,dp), min(f(i,j-1,s,t,dp),f(i-1,j-1,s,t,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        //memoization
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};