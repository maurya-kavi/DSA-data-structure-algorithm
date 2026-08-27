class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        unordered_map<char, int> mp;
        for (char ch : s) mp[ch]++;

        string prefix = "";
        int n = s.size(), m = target.size();

        // Greedily match target prefix as far as possible
        int i = 0;
        while (i < m && mp[target[i]] > 0) {
            mp[target[i]]--;
            prefix += target[i];
            i++;
        }

        // Helper to append remaining available characters in sorted order
        auto getSortedRemainder = [&](unordered_map<char, int>& freq) {
            string rem = "";
            for (char c = 'a'; c <= 'z'; c++) {
                if (freq[c] > 0) {
                    rem.append(freq[c], c);
                }
            }
            return rem;
        };

        // If target is fully matched and s is longer, remaining chars form the answer
        if (i == m && n > m) {
            return prefix + getSortedRemainder(mp);
        }

        //  Backtrack right-to-left to find the first valid divergence point
        for (int idx = i; idx >= 0; idx--) {
            if (idx < m) {
                char target_char = target[idx];
                char best_c = '{';

                // Find the smallest char strictly greater than target[idx]
                for (auto [key, cnt] : mp) {
                    if (cnt > 0 && key > target_char) {
                        best_c = min(best_c, key);
                    }
                }

                if (best_c != '{') {
                    // Diverge here: place best_c and append sorted remaining chars
                    mp[best_c]--;
                    prefix.resize(idx); 
                    prefix += best_c;
                    return prefix + getSortedRemainder(mp);
                }
            }

            // Undo match at idx - 1 and push character back to frequency map
            if (idx > 0) {
                char restored = prefix.back();
                prefix.pop_back();
                mp[restored]++;
            }
        }

        return "";
    }
};