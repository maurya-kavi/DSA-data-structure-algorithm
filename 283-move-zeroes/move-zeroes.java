class Solution {
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        int l=0, i=0;
        while(i<n){
            if(nums[i]!=0){
                int temp=nums[i];
                nums[i]=nums[l];
                nums[l]=temp;
                l++;
                i++;
            }else {
                i++;
            }
        }
    }
}