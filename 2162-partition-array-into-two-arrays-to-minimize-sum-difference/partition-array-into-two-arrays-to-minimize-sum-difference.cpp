class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        
        vector<vector<long long>> left(n + 1);
        vector<vector<long long>> right(n + 1);

        long long total = 0;
        for (int x : nums) total += x;

        generate(0, n, nums, 0, 0, left);
        generate(n, 2 * n, nums, 0, 0, right);

        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        long long ans = LLONG_MAX;

        for (int k = 0; k <= n; k++) {

            // Select k elements from left
            // Select n-k elements from right

            for (long long s1 : left[k]) {

                long long target = total / 2 - s1;

                auto &v = right[n - k];

                auto it = lower_bound(v.begin(), v.end(), target);

                if (it != v.end()) {
                    long long sum = s1 + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }

                if (it != v.begin()) {
                    --it;
                    long long sum = s1 + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
            }
        }

        return ans;
    }

    void generate(int i, int end, vector<int>& nums,
                  int cnt, long long sum,
                  vector<vector<long long>>& store) {

        if (i == end) {
            store[cnt].push_back(sum);
            return;
        }

        // Take
        generate(i + 1, end, nums,
                 cnt + 1, sum + nums[i], store);

        // Not take
        generate(i + 1, end, nums,
                 cnt, sum, store);
    }
};