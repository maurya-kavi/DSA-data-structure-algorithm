class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        for(int i=0; i<(n-1); i++){
            int need=k+nums[i];
            if(mp.find(need)!=mp.end()){
                cnt+=mp[need];
            }
        }
        return cnt;
    }
};