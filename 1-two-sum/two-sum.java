class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        int n=nums.length;
        for(int i=0; i<n; i++){
            int a=nums[i];
            int b=target-a;
            if(mp.containsKey(b)){
                return new int[]{mp.get(b),i};
            }else{
                mp.put(a,i);
            }
        }
        return new int[]{-1,-1};
    }
}