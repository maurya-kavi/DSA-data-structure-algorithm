class Solution {
    public int climbStairs(int n) {
        ArrayList<Integer>arr=new ArrayList<>(Collections.nCopies(n+1,0));
        arr.set(0,1);
        if(n>0) arr.set(1,1);
        for(int i=2; i<=n; i++){
            arr.set(i,arr.get(i-1)+arr.get(i-2));
        }
        return arr.get(n);
    }
}