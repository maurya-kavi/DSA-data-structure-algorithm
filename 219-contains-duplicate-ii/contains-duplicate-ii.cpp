class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp; // key,prevposition
        for(int i=0; i<n; i++){
            if(mp.count(nums[i])) {
                int diff=i-mp[nums[i]];
                if(diff<=k) return true;
                mp[nums[i]]=i;
            }else{
                mp[nums[i]]=i;
            }
        }
        return false;
    }
};