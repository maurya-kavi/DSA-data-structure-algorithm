class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        // you can always jump if array has no 0 element
        // you can jump in all the cases except in all possible jump yo are reaching at a position with 0 element
        int maxIdx=0;
        for(int i=0; i<n; i++){
            if(maxIdx>=n-1) return true;
            if(maxIdx==i && nums[i]==0) return false;
            maxIdx=max(maxIdx,i+nums[i]);
        }
        return true;
    }
};