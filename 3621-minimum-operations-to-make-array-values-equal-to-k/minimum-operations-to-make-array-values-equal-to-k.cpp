class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int s=nums[0];
        if(s<k) return -1;

        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int sz=nums.size();
        int ans=sz-1;
        if(s>k) ans++;
        return ans;
    }
};