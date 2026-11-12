class Solution {
    public int findMiddleIndex(int[] nums) {
        int n=nums.length;
        int lSum=0, rSum=0, totSum=0;
        for(int i=0; i<n; i++){
            totSum+=nums[i];
        }
        for(int i=0; i<n; i++){
            rSum=totSum-nums[i]-lSum;
            if(lSum==rSum) return i;
            lSum+=nums[i];
        }
        return -1;
    }
}