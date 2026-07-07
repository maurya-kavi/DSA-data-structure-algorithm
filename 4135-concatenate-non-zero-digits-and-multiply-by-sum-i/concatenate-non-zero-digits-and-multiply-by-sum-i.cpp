class Solution {
public:
using ll=long long;
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string s="";
        ll sum=0;
        while(n>0){
            ll rem=n%10;
            sum+=rem;
            if(rem!=0){
                s+=(rem+'0');
            }
            n/=10;
        }
        reverse(s.begin(),s.end());
        ll x=stoll(s);

        return 1LL*x*sum;
    }
};