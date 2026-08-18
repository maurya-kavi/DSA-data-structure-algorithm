class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n=nums.size();
        int ans=-1;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;

        if(n==k ){
            return *max_element(nums.begin(), nums.end());
        }

        if(k==1){
            for(auto [key,val]:mp){
                if(val==1) ans=max(ans,key);
            }
            return ans;
        }

        if(mp[nums[0]]==1) ans=max(ans, nums[0]);
        if(mp[nums[n-1]]==1) ans=max(ans, nums[n-1]);

        return ans;
    }
};