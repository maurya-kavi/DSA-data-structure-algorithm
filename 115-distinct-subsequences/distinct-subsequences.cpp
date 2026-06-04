class Solution {
public:
vector<vector<int>>dp;
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,s,t);
        
    }
    int solve(int i,int j, string &s, string &t){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(i+1,j+1,s,t) +
                   solve(i+1,j,s,t);
        }else{
            return dp[i][j]= solve(i+1,j,s,t);
        }
    }
};