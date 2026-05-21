class Solution {
public:
// optimization using rolling hash( rabin-karp algo)
    using ll = long long;

    const ll MOD = 1e9 + 7;
    const ll BASE = 911382323;

    vector<ll> power;
    vector<ll> pref;

    // build rolling hash
    void buildHash(vector<int>& nums) {

        int n = nums.size();

        power.resize(n + 1);
        pref.resize(n + 1);

        power[0] = 1;

        for(int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        pref[0] = 0;

        for(int i = 0; i < n; i++) {

            pref[i + 1] =
                (pref[i] * BASE + nums[i] + 1) % MOD;
        }
    }

    // hash of subarray [l..r]
    ll getHash(int l, int r) {

        ll hash =
            (pref[r + 1]
            - (pref[l] * power[r - l + 1]) % MOD
            + MOD) % MOD;

        return hash;
    }

    // check if some subarray of length len is unique
    bool check(int len, vector<int>& nums) {

        unordered_map<ll, int> freq;

        int n = nums.size();

        // count hashes
        for(int i = 0; i + len - 1 < n; i++) {

            ll h = getHash(i, i + len - 1);

            freq[h]++;
        }

        // any unique hash?
        for(auto &it : freq) {

            if(it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        buildHash(nums);

        int low = 1;
        int high = n;

        int ans = n;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(check(mid, nums)) {

                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};