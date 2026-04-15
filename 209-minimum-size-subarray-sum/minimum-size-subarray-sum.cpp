class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int l=0, r=0;
        int mn=INT_MAX;
        while(r<n){
            sum+=nums[r];
            while(l<n && sum>=target){
                mn=min(r-l+1, mn);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return (mn==INT_MAX ? 0:mn);
        
    }
};