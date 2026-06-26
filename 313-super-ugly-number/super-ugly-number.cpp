class Solution {
public:
using ll=long long ;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m=primes.size();
        vector<int>ind(m,0);

        vector<ll>dp(n);
        dp[0]=1;
        for(int i=1; i<n; i++){
            dp[i]=INT_MAX;
            for(int j=0; j<m; j++){
                dp[i]=min(dp[i],1LL*dp[ind[j]]*primes[j]);
            }
            for(int j=0; j<m; j++){
                if(dp[i]==dp[ind[j]]*primes[j]) ind[j]++;
            }
        }

        return dp[n-1];
    }
};