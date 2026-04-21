class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // return max_element(nums.begin(),nums.end())-nums.begin();
        //in this question, peak element doesn't always mean to be maximum
        // peak element is any element which is greater than their neig.
        int n=nums.size();
        int l=0, h=n-1;
        while(l<h){
            int mid=(l+h)/2;
            // given cond: nums[i] != nums[i + 1] for all valid i
            if(nums[mid]<nums[mid+1]) l=mid+1;
            else h=mid;
        }
        return h;
    }
};