class Solution {
public:
using ll=long long;
    long long countCommas(long long n) {
        if(n<1000) return 0;
        if(n<1e6) return n-999;
        ll prev=1e6-1e3;

        if(n<1e9) {
            return (n-1e6+1)*2+prev;
        }
        prev+=(2e9-2e6);

        if(n<1e12){
            return (n-1e9+1)*3+prev;
        }
        prev+=(3e12-3e9);

        if(n<1e15){
            return (n-1e12+1)*4 + prev;
        }
        prev+=4LL*(1e15-1e12);

        return prev+5;

    }
};