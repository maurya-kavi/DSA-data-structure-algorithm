class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int p=0,l=0,m=0;
        for(int i=0; i<n; i++){
            if(nums[i]==pivot) p++;
            else if(nums[i]<pivot) l++;
            else m++;
        }
        int li=0;
        int mi=n-m;
        int ei=l;
        for(int i=0; i<n; i++){
            if(nums[i]<pivot) {
                ans[li]=nums[i];
                li++;
            }
            else if(nums[i]>pivot){
                ans[mi]=nums[i];
                mi++;
            }else{
                //equal
                ans[ei]=nums[i];
                ei++;
            }
        }
        return ans;
    }
};