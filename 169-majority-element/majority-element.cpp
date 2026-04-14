class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto it:nums){
            mp[it]++;
        }
        int mx=0;
        for(auto [key,fre]:mp){
            mx=max(mx,fre);
            if(mx>n/2){
                return key;
            }
        }
        return 0;
    }
};