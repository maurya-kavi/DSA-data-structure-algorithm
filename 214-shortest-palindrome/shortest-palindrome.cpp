class Solution {
public:
    // Helper function to build the LPS array
    vector<int> computeLPS(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Fall back to the previous known prefix
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int n=s.size();
        string temp=s+"-"+rev;
        vector<int>lps=computeLPS(temp);
        int matchedLen=lps[temp.size()-1];
        return rev.substr(0,(n-matchedLen))+s;
    }
};






