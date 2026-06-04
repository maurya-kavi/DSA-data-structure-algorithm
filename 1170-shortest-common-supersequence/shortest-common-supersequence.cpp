class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        // so lets go with the same approach as we have used for the lcs (longest common subsequences)
        //Build the DP Map for the Longest Common Subsequence
        // We use the (n+1) x (m+1) buffer technique to avoid edge cases.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        //Walk backward to forge the Shortest Common Supersequence
        string result = "";
        int i = n, j = m;
        
        while (i > 0 && j > 0) {
            // If the characters match, they belong to the skeleton (LCS).
            // We write it ONCE, and step diagonally backward.
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--;
                j--;
            } 
            // If they clash, we look at the DP map. 
            // We move in the direction that gave us the larger LCS.
            // But before we move, we MUST include the character we are leaving behind.
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                result += str1[i - 1];
                i--; // Moving UP
            } 
            else {
                result += str2[j - 1];
                j--; // Moving LEFT
            }
        }
        
        // Sweep up the remaining fragments
        // If one string was exhausted before the other, we must add the leftover characters.
        while (i > 0) {
            result += str1[i - 1];
            i--;
        }
        while (j > 0) {
            result += str2[j - 1];
            j--;
        }
        
        // Because we walked backward, our string is backwards. 
        // We reverse it to reveal the truth.
        reverse(result.begin(), result.end());
        
        return result;
    }

    //recursion code
    // void solve(int i,int j, int n, int m, string &str1, string &str2, string &result, string temp){
    //     if(i==n && j==m){
            
    //         if(result=="" || result.size()>temp.size()) result=temp;
    //         return;
    //     }
    //     if(i==n){
    //         // add the remaining chars of the str2
    //         temp+=str2.substr(j);
    //         if(result=="" || result.size()>temp.size()) result=temp;
    //         return;
    //     }
    //     if(j==m){
    //         // add the remaining chars of the str2
    //         temp+=str1.substr(i);
    //         if(result=="" || result.size()>temp.size()) result=temp;
    //         return;
    //     }

    //     if(str1[i]==str2[j]){
    //         solve(i+1,j+1,n,m,str1,str2,result,temp+str1[i]);
    //     }else{
    //         solve(i+1,j,n,m,str1,str2,result,temp+str1[i]);
    //         solve(i,j+1,n,m,str1,str2,result,temp+str2[j]);
    //     }
    // }
};