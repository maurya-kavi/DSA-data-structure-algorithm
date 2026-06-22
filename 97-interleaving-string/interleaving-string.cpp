class Solution {
public:
int dp[101][101][201];
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int N=s3.size();
        if(n+m != N) return false;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0, s1,s2,s3, n,m,N);
    }

    bool solve(int i,int j,int k, string &s1, string s2, string &s3, int &n, int &m , int &N){

        if(i==n && j==m && k==N) return true;

        if(k>=N) return false;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool x=false, y=false;
        if(s1[i]==s3[k]) x=solve(i+1,j,k+1,s1,s2,s3,n,m,N);
        if(s2[j]==s3[k]) y=solve(i,j+1,k+1,s1,s2,s3,n,m,N);

        // if(s1[i]!=s3[k] && s2[j]!=s3[k]) return false;

        return dp[i][j][k] = x || y;
    }
};