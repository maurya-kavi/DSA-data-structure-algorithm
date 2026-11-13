class Solution {
    public int removeDuplicates(int[] nums) {
        int n=nums.length;
        int[] arr=new int[n];
        int i=0;
        arr[i]=nums[0];
        i=i+1;
        for(int j=1; j<n; j++){
            if(nums[j]==nums[j-1]) continue;
            else{
                nums[i]=nums[j];
                i++;
            }
        }
        return i; // we have to return the actaul length of arr
    }
}