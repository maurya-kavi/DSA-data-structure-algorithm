class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        int n=nums.length;
        for(int i=0; i<n; i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }
        for(Map.Entry<Integer,Integer>entry:mp.entrySet()){
            int key=entry.getKey();
            int value=entry.getValue();
            if(value>(n/2)) return key;
        }
        return -1;
    }
}