class Solution {
public:
    // implemented using KMP algo + dp
    long long sumScores(string s) {
        int n = s.length();
        if (n == 0) return 0;

        // Build the pi table (LPS array)
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;
        
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Fall back to the previous echo
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        //  DP on the pi table to count prefix echoes
        long long totalScore = 0;
        vector<long long> dp(n, 0);
        
        for (int j = 0; j < n; j++) {
            // Every index inherently ends exactly one full prefix: the substring S[0...j]
            dp[j] = 1;
            
            // If the LPS array tells us a smaller, proper prefix also ends here,
            // we inherit all the echoes from that prefix's ending index.
            if (lps[j] > 0) {
                dp[j] += dp[lps[j] - 1];
            }
            
            // Add the total number of prefixes ending at index j to the grand total
            totalScore += dp[j];
        }
        
        return totalScore;

    }
};