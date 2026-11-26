class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        for (int ans = 1; ans <= n + 1; ans++) {
            if (st.find(ans) == st.end()) {
                return ans;
            }
        }
        return n + 1;
    }
};
