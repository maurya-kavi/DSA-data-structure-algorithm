class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int mod=1e9+7;
        vector<int>dp(r+1);
        dp.assign(r+1,1);

        for(int i=1; i<n; i++){
            vector<int>next_dp(r+1);
            if(i%2!=0){ // odd->increaing
                int pre=0;
                for(int j=l; j<=r; j++){
                    next_dp[j]=(pre)%mod;
                    pre=(pre+dp[j])%mod;
                }
            }else{
                int suf=0;
                for(int j=r; j>=l; j--){
                    next_dp[j]=suf%mod;
                    suf=(suf+dp[j])%mod;
                }
            }
            dp=next_dp;
        }
        int cnt=0;
        for(int i=l; i<=r; i++){
            cnt=(cnt+dp[i])%mod;
        }
        return 2*cnt%mod;
    }
};