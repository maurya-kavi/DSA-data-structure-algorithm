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
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps=computeLPS(s);
        int len=lps[n-1];
        if(len==0) return "";
        return s.substr(n-len);
    }
};