class Solution {
    public int[] replaceElements(int[] arr) {
        int n=arr.length;
        // ArrayList<Integer>a=new ArrayList<>(n);
        int[] a=new int[n];
        a[n-1]=-1;
        int mx=arr[n-1];
        for(int i=n-2; i>=0; i--){
            a[i]=mx;
            mx=Math.max(arr[i],mx);
        }
        return a;
    }
}