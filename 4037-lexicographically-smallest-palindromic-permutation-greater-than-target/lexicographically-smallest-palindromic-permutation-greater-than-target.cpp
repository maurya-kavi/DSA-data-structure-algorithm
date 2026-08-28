class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int odd_cnt = 0;
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd_cnt++;
                mid = 'a' + i;
            }
            cnt[i] /= 2;
        }

        if (odd_cnt > 1) return "";

        int L = n / 2;
        vector<int> pool = cnt;
        int max_match = 0;
        
        while (max_match < L && pool[target[max_match] - 'a'] > 0) {
            pool[target[max_match] - 'a']--;
            max_match++;
        }

        if (max_match == L) {
            string H = target.substr(0, L);
            string P = H;
            if (n % 2) P += mid;
            string H_rev = H;
            reverse(H_rev.begin(), H_rev.end());
            P += H_rev;
            
            if (P > target) return P;
            
            if (L > 0) {
                pool[target[L - 1] - 'a']++;
                max_match = L - 1;
            } else {
                max_match = -1;
            }
        }

        for (int i = max_match; i >= 0; i--) {
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (pool[c] > 0) {
                    string H = target.substr(0, i);
                    H += (char)('a' + c);
                    pool[c]--;
                    
                    for (int j = 0; j < 26; j++) {
                        while (pool[j] > 0) {
                            H += (char)('a' + j);
                            pool[j]--;
                        }
                    }
                    
                    string P = H;
                    if (n % 2) P += mid;
                    string H_rev = H;
                    reverse(H_rev.begin(), H_rev.end());
                    P += H_rev;
                    
                    return P;
                }
            }
            if (i > 0) pool[target[i - 1] - 'a']++;
        }

        return "";
    }
};