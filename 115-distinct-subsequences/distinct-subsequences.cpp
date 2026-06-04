class Solution {
public:
// tabulation , 
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        
        // Use unsigned long long to safely absorb phantom branches
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // Base case: empty t can always be formed exactly 1 way
        for(int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        // Build the truth backward
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        // answer in 32 bit int
        return (int)dp[0][0];
        
    }

    // recursive code with memoization
    // int solve(int i,int j, string &s, string &t){
    //     if(j==t.size()) return 1;
    //     if(i==s.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]){
    //         return dp[i][j]=solve(i+1,j+1,s,t) +
    //                solve(i+1,j,s,t);
    //     }else{
    //         return dp[i][j]= solve(i+1,j,s,t);
    //     }
    // }
};