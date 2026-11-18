class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n=nums1.length;
        int m=nums2.length;
        int left=(n+m-1)/2;
        int i=0, j=0;
        while(i<n && j<m && left>0){
            if(nums1[i]<=nums2[j]) i++;
            else j++;
            left--;
        }
        while(left>0 && i<n){
            i++;
            left--;
        }
        while(left>0 && j<m){
            j++;
            left--;
        }
        int a=0;
        if(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                a=nums1[i];
                i++;
            }else{
                a=nums2[j];
                j++;
            }
        }
        else if(i<n){
            a=nums1[i];
            i++;
        }else{
            a=nums2[j];
            j++;
        }

        int b=0;
        if((n+m)%2==0){
            if(i<n && j<m){
                if(nums1[i]<=nums2[j]){
                    b=nums1[i];
                    i++;
                }else{
                    b=nums2[j];
                    j++;
                }
            }
            else if(i<n){
                b=nums1[i];
                i++;
            }else{
                b=nums2[j];
                j++;
            }
            return (double)(a+b)/2.0;
        }
        return (double)(a);
    }
}