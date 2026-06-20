class Solution {
    using ull = unsigned long long;
    const ull p = 1000003;
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.length();
        vector<ull> pref(n + 1, 0);
        vector<ull> power(n + 1, 1);
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * p + (word[i] - 'a' + 1);
            power[i + 1] = power[i] * p;
        }
        
        // O(1) time extraction 
        auto getHash = [&](int l, int r) -> ull {
            // ull overflow acts as a zero-cost modulo 2^64
            return pref[r + 1] - pref[l] * power[r - l + 1];
        };
        
        int time = 1;
        
        for (int i = k; i < n; i += k) {
            int remaining_len = n - i;
            
            // Does the surviving suffix perfectly echo the prefix?
            if (getHash(i, n - 1) == getHash(0, remaining_len - 1)) {
                return time;
            }
            time++;
        }
        
        return (n + k - 1) / k; 
    }
};