class Solution {
    public int subarraySum(int[] nums, int k) {
        int n=nums.length;
        HashMap<Integer,Integer>mp=new HashMap<>();
        int sum=0,ans=0;
        mp.put(0,1);
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int x=sum-k; // current sum mein se x ko hta diya jaye toh k mil jayega
            if(mp.containsKey(x)){
                int fre=mp.get(x);
                ans+=fre;
            }
            mp.put(sum,mp.getOrDefault(sum,0)+1);
        }
        return ans;
    }
}