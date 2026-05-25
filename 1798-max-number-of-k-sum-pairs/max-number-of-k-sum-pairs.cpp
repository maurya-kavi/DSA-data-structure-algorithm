class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool>vis(n,false);
        int ans=0;
        sort(nums.begin(),nums.end());
        int l=0, r=n-1;
        while(l<r){
            if(nums[l]+nums[r] == k) {
                ans++;
                l++, r--;
            }
            else if(nums[l]+nums[r] >k) r--;
            else l++;
        }
        return ans;
    }
};