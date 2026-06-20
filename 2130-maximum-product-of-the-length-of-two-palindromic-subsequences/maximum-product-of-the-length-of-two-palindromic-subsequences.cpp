class Solution {
    int max_prod = 0;

    bool isPalindrome(const string& str) {
        int l = 0, r = (int)str.length() - 1;
        while (l < r) {
            if (str[l++] != str[r--]) return false;
        }
        return true;
    }

    void explore(const string& s, int i, string& s1, string& s2) {
        if (i == s.length()) {
            if (isPalindrome(s1) && isPalindrome(s2)) {
                int prod = s1.length() * s2.length();
                if (prod > max_prod) {
                    max_prod = prod;
                }
            }
            return;
        }

        explore(s, i + 1, s1, s2);

        s1.push_back(s[i]);
        explore(s, i + 1, s1, s2);
        s1.pop_back();

        s2.push_back(s[i]);
        explore(s, i + 1, s1, s2);
        s2.pop_back();
    }

public:
    int maxProduct(string s) {
        string s1 = "", s2 = "";
        explore(s, 0, s1, s2);
        return max_prod;
    }
};