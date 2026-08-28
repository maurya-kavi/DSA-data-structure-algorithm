class Solution {

    // recursive approach 
    bool solve(int i, bool greater, string& curr, vector<int>& cnt, const string& t, int n, string& res) {
        if (i == n) {
            if (greater || n > t.length()) {
                res = curr;
                return true;
            }
            return false;
        }
        
        for (int c = 0; c < 26; c++) {
            if (cnt[c] > 0) {
                char ch = c + 'a';
                bool nxt = greater;
                
                if (!greater) {
                    if (i < t.length()) {
                        if (ch < t[i]) continue;
                        if (ch > t[i]) nxt = true;
                    } else {
                        nxt = true;
                    }
                }
                
                cnt[c]--;
                curr.push_back(ch);
                
                if (solve(i + 1, nxt, curr, cnt, t, n, res)) return true;
                
                curr.pop_back();
                cnt[c]++;
            }
        }
        return false;
    }
    
public:
    string lexGreaterPermutation(string s, string t) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        string curr = "", res = "";
        solve(0, false, curr, cnt, t, s.length(), res);
        return res;
    }
};