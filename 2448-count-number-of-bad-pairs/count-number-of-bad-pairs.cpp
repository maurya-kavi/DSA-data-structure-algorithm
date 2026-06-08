class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        unordered_map<int,int>mp;
        mp[nums[0]-0]++;
        for(int i=1; i<n; i++){
            int x=nums[i]-i;
            int pairs=i; // if no good pair
            if(mp.find(x)!=mp.end()) {
                pairs-=mp[x];
            }
            cnt+=(1LL*pairs);
            mp[x]++;
        }
        return cnt;
    }
};

// bad pairs : j-i != nums[j]-nums[i];
// so good pair : j-i = nums[j]-nums[i] => nums[i]-i = nuns[j]=j;
