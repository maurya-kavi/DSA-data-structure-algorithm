class Solution {
    // using rolling hash (single hashing)
    using ull = unsigned long long;
    const ull p = 1000003; // prime base

    vector<int> getMatches(const string& s, const string& pattern) {
        vector<int> matches;
        int n = s.length();
        int m = pattern.length();
        
        if (m > n) return matches;

        ull hp = 1;
        ull target = 0;
        ull curr = 0;

        for (int i = 0; i < m - 1; i++) {
            hp *= p;
        }

        for (int i = 0; i < m; i++) {
            target = target * p + (pattern[i] - 'a' + 1);
            curr = curr * p + (s[i] - 'a' + 1);
        }

        if (curr == target) {
            matches.push_back(0);
        }

        for (int i = m; i < n; i++) {
            curr = curr - (s[i - m] - 'a' + 1) * hp;
            curr = curr * p + (s[i] - 'a' + 1);

            if (curr == target) {
                matches.push_back(i - m + 1);
            }
        }

        return matches;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> A = getMatches(s, a);
        vector<int> B = getMatches(s, b);
        vector<int> ans;

        for (int i : A) {
            auto it = lower_bound(B.begin(), B.end(), i - k);
            if (it != B.end() && *it <= i + k) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};