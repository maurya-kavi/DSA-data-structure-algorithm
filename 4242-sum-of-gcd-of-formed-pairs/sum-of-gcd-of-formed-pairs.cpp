class Solution {
public:
using ll = long long;
    long long gcdSum(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>pregcd(n);
        ll mx=0;
        for(ll i=0; i<n; i++){
            mx=max(mx,nums[i]*1LL);
            pregcd[i]=gcd(mx,nums[i]);
        }

sort(pregcd.begin(),pregcd.end());

        ll m=n/2;
ll sum=0;
        ll r=n-1;
        for(int i=0; i<m; i++){
            sum+=gcd(pregcd[i],pregcd[r]);
            r--;
        }
        return sum;
    }
};