class Solution {
public:
vector<int>inc,dec;
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        inc.resize(n,1);
        dec.resize(n,1);
int ans=1;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]) inc[i]=inc[i-1]+1; //for longest increasing

            if(nums[i]<nums[i-1]) dec[i]=dec[i-1]+1; //for longest decreasing

            ans=max(ans,inc[i]);
            ans=max(ans, dec[i]);
            
        }
        return ans;
    }

};