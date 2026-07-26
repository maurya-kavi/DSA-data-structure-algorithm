class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        vector<bool>vis(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtrack(nums,vis,curr,res);

        return res;
    }

    void backtrack(vector<int>&nums, vector<bool>&vis, vector<int>&curr, vector<vector<int>>&res){
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return ;
        }

        for(int i=0; i<nums.size(); i++){
            if(vis[i] || (i>0 && nums[i]==nums[i-1] && !vis[i-1])) continue;

            vis[i]=true;
            curr.push_back(nums[i]);

            backtrack(nums,vis,curr,res);

            curr.pop_back();
            vis[i]=false;
        }
    }
};