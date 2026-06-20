class Solution {
public:
#define ll long long
#define ull unsigned long long
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        int ans=0;
        // to check the distinct subarray we won't store the substring , we will be storing the hash value
        set<ull>store;
        ll power=211;
        for(int i=0; i<n; i++){
            int cnt=0;
            ull hashVal=0;
            for(int j=i; j<n; j++){
                if(nums[j]%p==0) cnt++;
                if(cnt>k) break;

                hashVal=(hashVal*power+nums[j]);
                if (!store.count(hashVal)) {
                    ans++;
                    store.insert(hashVal);
                }
            }
        }
        return ans;
    }
};