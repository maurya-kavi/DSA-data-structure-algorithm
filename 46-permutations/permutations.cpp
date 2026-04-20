class Solution {
public:

    vector<vector<int>>result;
    void solve(int idx, vector<int>&nums){
        int n=nums.size();
        if(idx==n){
            result.push_back(nums);
            return;
        }
//choose an element and swap t wit every element , and do it for every element
// aur kisi bhi element ka swapping start hoga o ussi ke index se start hoga and right ki taraf move karege

        for(int i=idx; i<n; i++){
            swap(nums[i],nums[idx]); 
            solve(idx+1,nums);
            //backtrack
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        solve(0,nums);
        return result;
    }
};