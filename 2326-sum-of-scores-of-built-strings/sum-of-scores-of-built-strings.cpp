class Solution {
public:
    // implemented using z-algo
    long long sumScores(string s) {
        int n = s.length();
        if (n == 0) return 0;

        vector<int> z(n, 0);
        int l = 0, r = 0;
        
        // The score of the full string itself is always its total length.
        long long totalScore = n; 

        // Calculate the Z-array for all suffixes starting from index 1
        for (int i = 1; i < n; i++) {
            // If 'i' is inside the known mirrored window, we can fast-forward
            // by taking the minimum of the remaining window length or the previously computed Z-value
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            
            // Try to stretch the vision further beyond our current limits
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            
            // If we pushed the boundary further right, update the window [L, R]
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
            
            // The Z-value is exactly the score for this suffix. Add it instantly.
            totalScore += z[i];
        }

        return totalScore;

    }
};