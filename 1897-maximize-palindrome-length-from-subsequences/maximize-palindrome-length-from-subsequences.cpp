class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n1 = word1.length();
        int n = s.length();
        
        // dp[i][j] represents the length of the longest 
        // palindromic subsequence within s[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int max_len = 0;
        
        // Base state---- Every single character is a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // observe the recursion ind and in similar fashion form the loops
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                
                if (s[i] == s[j]) {
                    // The edges match, the palindrome grows
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                    
                    // Does this anchor bridge the two worlds?, dono mein s atleasat ek char aana chahiye,  we will only consider the max_len if i is strictly inside the word1 and rthe right index j should consider some elements of the word2
                    
                    if (i < n1 && j >= n1) {
                        max_len = max(max_len, dp[i][j]);
                    }
                } else {
                    // The edges clash, find the best survivor
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return max_len;
    }
};