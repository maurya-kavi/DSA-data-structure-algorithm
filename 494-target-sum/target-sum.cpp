class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return rec(0,nums,target);
    }
    int rec(int ind, vector<int>&nums, int target){
        if(target==0 && ind==nums.size()) return 1;
        if(ind==nums.size()) return 0;

        // taking with +
        int sum1=rec(ind+1,nums,target-nums[ind]);
        
        // taking with -
        int sum2=rec(ind+1,nums,target+nums[ind]);

        return sum1+sum2;
    }
};