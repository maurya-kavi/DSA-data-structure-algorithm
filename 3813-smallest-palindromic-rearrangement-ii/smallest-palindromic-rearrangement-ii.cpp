class Solution {
    // calculate the number of permutations of a multiset
    long long get_ways(const vector<int>& freq) {
        long long ways = 1;
        int sum = 0;
        int max_f = 0, max_idx = -1;
        
        // Find the character with the highest frequency
        for (int i = 0; i < 26; i++) {
            if (freq[i] > max_f) {
                max_f = freq[i];
                max_idx = i;
            }
        }
        
        if (max_f == 0) return 1;

        //lit bit Optimization: Start our base sum with the largest frequency. 
        // This effectively skips thousands of redundant loop iterations.
        sum = max_f;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0 || i == max_idx) continue;
            for (int j = 1; j <= freq[i]; j++) {
                sum++;
                ways = ways * sum / j;
                // Cap to prevent overflow. We only need to know if it's >= k
                if (ways > 1e10) return 1e10 + 1; 
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, long long k) {
        vector<int> mp(26, 0);
        for (char ch : s) mp[ch - 'a']++;
        
        int odd_cnt = 0;
        char odd_char = 0;
        vector<int> left_freq(26, 0);
        int L = 0;
        
        // Build the frequency map for the left half
        for (int i = 0; i < 26; i++) {
            if (mp[i] % 2 != 0) {
                odd_cnt++;
                odd_char = i + 'a';
            }
            left_freq[i] = mp[i] / 2;
            L += left_freq[i];
        }
        
        // If it cannot form a palindrome (or doesn't have k permutations)
        long long total_palindromes = get_ways(left_freq);
        if (odd_cnt > 1 || total_palindromes < k) return "";
        
        string left_half = "";
        
        // Construct the left half position by position
        for (int i = 0; i < L; i++) {
            for (int c = 0; c < 26; c++) {
                if (left_freq[c] > 0) {
                    left_freq[c]--; // Try placing character 'c'
                    
                    long long ways = get_ways(left_freq);
                    
                    if (k <= ways) {
                        // 'c' is the correct character for this position
                        left_half += (char)(c + 'a');
                        break; 
                    } else {
                        // The k-th permutation does not start with 'c'. 
                        // Subtract the ways and backtrack.
                        k -= ways;
                        left_freq[c]++;
                    }
                }
            }
        }
        
        // Construct the final palindrome
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        
        string res = left_half;
        if (odd_cnt == 1) res += odd_char;
        res += right_half;
        
        return res;
    }
};