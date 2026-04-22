class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq; //max-heap
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        int f=k-1;
        for(int i=1; i<=f; i++){
            pq.pop();
        }

        return pq.top();
    }
};