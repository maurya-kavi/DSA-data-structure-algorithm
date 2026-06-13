class MergeSorter {
private:
    void merge(vector<int>& arr, int left, int mid, int right) {
        // Calculate the sizes of the two fractured arrays
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Allocate auxiliary memory - the cost of Merge Sort
        vector<int> L(n1), R(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        // Weave the two sorted halves back into the original array
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        // Exhaust any remaining elements
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    int count(vector<int>&arr, int left,int mid,int right){
        int cnt=0;
        int rightpointer=mid+1;
        for(int i=left; i<=mid; i++){
            while(rightpointer<=right && 1LL*arr[i]>1LL*2*arr[rightpointer]) rightpointer++;
            cnt=cnt+(rightpointer-(mid+1));
        }
        return cnt;
    }

public:
    void sort(vector<int>& arr, int left, int right,int &totcnt) {
        if (left >= right) return; // Base case: an array of 1 is already sorted

        // Find the midpoint to cleanly divide the array
        int mid = left + (right - left) / 2;

        // Recursively shatter the array into pieces
        sort(arr, left, mid,totcnt);
        sort(arr, mid + 1, right,totcnt);

        totcnt+=count(arr,left,mid,right);

        // Forge them back together
        merge(arr, left, mid, right);
    }
};


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        MergeSorter ms;
        int totcnt=0;
        ms.sort(nums,0,nums.size()-1, totcnt);
        return totcnt;
    }
};