class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        return cntAtMost(nums,k)-cntAtMost(nums,k-1);
    }

// no of subarray with less than or equaal to the k odd numbers 
    int cntAtMost(vector<int>&nums,int k){
        int n=nums.size();
        int l=0, cntt=0;
        int res=0;
        if(k<0) return 0;
        for(int r=0; r<n; r++){
            if(nums[r]&1) cntt++;
            while(cntt>k){
                if(nums[l]&1) cntt--;
                l++;
            }
            res+=(r-l+1); 
        }
        return res;
    }
};