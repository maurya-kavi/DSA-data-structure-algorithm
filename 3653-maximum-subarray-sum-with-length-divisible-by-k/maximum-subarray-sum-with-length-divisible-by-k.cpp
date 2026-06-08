class Solution {
public:
#define ll long long
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<ll>pre(n);
        for(int i=0; i<n; i++){
            if(i==0) pre[i]=nums[i];
            else pre[i]=pre[i-1]+nums[i];
        }
        ll mxSum=LLONG_MIN;
        unordered_map<ll,ll>mp;
        mp[0]=0; // for rem =0, store the min val as 0
// store min we need to subtract as the left part from the curr subarray of len i+1
        for(int i=0; i<n; i++){
            int curr_len=i+1;
            // (i-j) % k = 0 => i%k=j%k;
            if(mp.find(curr_len%k)!=mp.end()){
                ll val=pre[i]-mp[curr_len%k];
                mxSum=max(mxSum,val);
            }
            ll curr_pre_val=pre[i];
            if(mp.find(curr_len%k)!=mp.end()) mp[curr_len%k]=min(mp[curr_len%k],curr_pre_val);
            else mp[curr_len%k]=curr_pre_val;
        }
        return mxSum;
    }
};