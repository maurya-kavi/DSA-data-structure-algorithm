class Solution {
public:

// optimised usinngg map
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int need = target - nums[i];

            // If complement already exists
            if(mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            // Store current number and index
            mp[nums[i]] = i;
        }

        return {};
    }
};