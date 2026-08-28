class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
       int n = s.length(), m = t.length();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        int i = 0;
        while (i < n && i < m && cnt[t[i] - 'a'] > 0) {
            cnt[t[i] - 'a']--;
            i++;
        }
        
        if (i < n && i < m) {
            for (int c = t[i] - 'a' ; c < 26; c++) {
                if (cnt[c] > 0) {
                    string res = t.substr(0, i) + (char)('a' + c);
                    cnt[c]--;
                    for (int j = 0; j < 26; j++) res += string(cnt[j], 'a' + j);
                    return res;
                }
            }
        } else if (i == m && i < n) {
            for (int c = 0; c < 26; c++) {
                if (cnt[c] > 0) {
                    string res = t.substr(0, i) + (char)('a' + c);
                    cnt[c]--;
                    for (int j = 0; j < 26; j++) res += string(cnt[j], 'a' + j);
                    return res;
                }
            }
        }
        
        while (i > 0) {
            i--;
            cnt[t[i] - 'a']++;
            for (int c = t[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string res = t.substr(0, i) + (char)('a' + c);
                    cnt[c]--;
                    for (int j = 0; j < 26; j++) res += string(cnt[j], 'a' + j);
                    return res;
                }
            }
        }
        
        return "";
    }
};