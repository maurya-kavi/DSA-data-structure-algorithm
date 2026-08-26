class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = 1e9, ans = 1e9;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int take = 0;
            
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    take++;
                    i++; 
                }
            }
            
            if (take >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};