class Solution {
public:
using ll=long long;
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,ll>mp;
        int cnt1=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) cnt1++;
            else mp[nums[i]]++;
        }

        if(cnt1!=0 && cnt1%2==0) cnt1--;
        int ans=cnt1;

        for(auto [num,fre]:mp){

            ll prevVal=sqrt(num);
            if(1LL*prevVal*prevVal==1LL*num && mp.count(prevVal) && mp[prevVal]>=2) continue;

            // if started from num , what should be the maximum length subarray ?
            int len=0;
            ll searchfor=num;
            while(mp.count(searchfor) && mp[searchfor]>=2){
                len+=2;
                searchfor=(searchfor*searchfor);
                
            }
            if(mp.count(searchfor) && mp[searchfor]==1) len++;
            else len--;

            ans=max(ans,len);
        }
        return ans;
    }
};