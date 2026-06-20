class Solution {
    using ull = unsigned long long;
    const ull m1 = 1e9 + 7;
    const ull m2 = 1e9 + 9;
    const ull b1 = 100003;
    const ull b2 = 100019;
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        // double hashing technique (rolling hash)
        unordered_map<ull, int> vault;
        long long ans = 0;

        for (const string& word : words) {
            int len = word.length();
            ull pref1 = 0, pref2 = 0;
            ull suff1 = 0, suff2 = 0;
            ull hp1 = 1, hp2 = 1;

            for (int i = 0; i < len; i++) {
                pref1 = (pref1 * b1 + (word[i] - 'a' + 1)) % m1;
                pref2 = (pref2 * b2 + (word[i] - 'a' + 1)) % m2;

                suff1 = ((word[len - 1 - i] - 'a' + 1) * hp1 + suff1) % m1;
                suff2 = ((word[len - 1 - i] - 'a' + 1) * hp2 + suff2) % m2;

                hp1 = (hp1 * b1) % m1;
                hp2 = (hp2 * b2) % m2;

                if (pref1 == suff1 && pref2 == suff2) {
                    ull combined = (pref1 << 32) | pref2;
                    auto it = vault.find(combined);
                    if (it != vault.end()) {
                        ans += it->second;
                    }
                }
            }

            ull final_combined = (pref1 << 32) | pref2;
            vault[final_combined]++;
        }

        return ans;
    }
};