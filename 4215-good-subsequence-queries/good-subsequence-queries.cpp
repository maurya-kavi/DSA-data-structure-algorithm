class SegmentTree {
public:
    int n;
    vector<int> seg;

    SegmentTree(int sz) {
        n = sz;
        seg.resize(4 * n);
    }

    int gcdVal(int a, int b) {
        return gcd(a, b);
    }

    void build(int idx, int l, int r, vector<int>& arr) {

        if (l == r) {
            seg[idx] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid, arr);
        build(2 * idx + 2, mid + 1, r, arr);

        seg[idx] =
            gcdVal(seg[2 * idx + 1],
                   seg[2 * idx + 2]);
    }

    void update(int idx, int l, int r,
                int pos, int val) {

        if (l == r) {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        seg[idx] =
            gcdVal(seg[2 * idx + 1],
                   seg[2 * idx + 2]);
    }

    int query(int idx, int l, int r,
              int ql, int qr) {

        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        return gcdVal(
            query(2 * idx + 1, l, mid, ql, qr),
            query(2 * idx + 2, mid + 1, r, ql, qr)
        );
    }
};

class Solution {
public:

    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {

        int n = nums.size();

        vector<int> arr(n);

        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] % p == 0) {
                arr[i] = nums[i] / p;
                cnt++;
            }
            else {
                arr[i] = 0;
            }
        }

        SegmentTree st(n);
        st.build(0, 0, n - 1, arr);

        int ans = 0;

        for (auto &q : queries) {

            int idx = q[0];
            int val = q[1];

            // remove old contribution
            if (nums[idx] % p == 0)
                cnt--;

            nums[idx] = val;

            // add new contribution
            if (val % p == 0) {
                arr[idx] = val / p;
                cnt++;
            }
            else {
                arr[idx] = 0;
            }

            st.update(0, 0, n - 1, idx, arr[idx]);

            // no divisible elements
            if (cnt == 0)
                continue;

            int totalGCD =
                st.query(0, 0, n - 1, 0, n - 1);

            // impossible
            if (totalGCD != 1)
                continue;

            // already proper subsequence
            if (cnt < n) {
                ans++;
                continue;
            }

            // all divisible -> remove one index
            bool ok = false;

            for (int i = 0; i < n; i++) {

                int leftGCD = 0;
                int rightGCD = 0;

                if (i > 0)
                    leftGCD =
                        st.query(0, 0, n - 1, 0, i - 1);

                if (i + 1 < n)
                    rightGCD =
                        st.query(0, 0, n - 1, i + 1, n - 1);

                if (gcd(leftGCD, rightGCD) == 1) {
                    ok = true;
                    break;
                }
            }

            if (ok)
                ans++;
        }

        return ans;
    }
};