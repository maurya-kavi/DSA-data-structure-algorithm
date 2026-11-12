class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n=nums2.length;
        HashMap<Integer, Integer>mp=new HashMap<>();
        Stack<Integer>st=new Stack<>();
        //nums 2 ka next greater element find karenge and iska relation hashmap mein store kar denge
        mp.put(nums2[n-1],-1);
        st.push(nums2[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && st.peek()<=nums2[i]) st.pop();
            if(st.empty()) mp.put(nums2[i],-1);
            else mp.put(nums2[i],st.peek());
            st.push(nums2[i]);
        }
        int m=nums1.length;
int[] ansArr=new int[m];
        for(int i=0; i<nums1.length; i++){
            ansArr[i]=mp.get(nums1[i]);
        }
        return ansArr;
    }
}