class Solution {
public:
// here is my dp solution, which is very similar to the problem like LCS , longest common subsequence

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Base case: single character
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        int mxlen=1;
        int startingInd=0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {

                if (s[i] == s[j]) {
                    if(j-i==1 || dp[i+1][j-1]==true){
                        dp[i][j]=true;
                        if(j-i+1>mxlen){
                            mxlen=j-i+1;
                            startingInd=i;
                        }
                    }
                } else {
                    dp[i][j] = false;
                    
                }
            }
        }

        return s.substr(startingInd,mxlen);
    }


};


