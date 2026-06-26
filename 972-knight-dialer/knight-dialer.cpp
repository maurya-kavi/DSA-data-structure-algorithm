class Solution {
public:
const int mod=1e9+7;
int dp[10][5001];
    int knightDialer(int n) {
        vector<vector<int>>v(10);
        v[0].push_back(4);
        v[0].push_back(6);
        v[1].push_back(6);
        v[1].push_back(8);
        v[2].push_back(9);
        v[2].push_back(7);
        v[3].push_back(4);
        v[3].push_back(8);
        v[4].push_back(0);
        v[4].push_back(3);
        v[4].push_back(9);
        // v[5].push_back({});
        v[6].push_back(0);
        v[6].push_back(1);
        v[6].push_back(7);
        v[7].push_back(2);
        v[7].push_back(6);
        v[8].push_back(1);
        v[8].push_back(3);
        v[9].push_back(2);
        v[9].push_back(4);

        memset(dp,-1,sizeof(dp));

        int ans=0;
        for(int i=0; i<10; i++){
            ans=(ans+solve(i,n,v))%mod;
        }
        return ans;
        
    }

    int solve(int i, int n, vector<vector<int>>&v){
        if(n==1) return 1;
        if(dp[i][n]!=-1) return dp[i][n];
        int cnt=0;
        for(auto &val:v[i]){
            cnt=(cnt+solve(val,n-1,v))%mod;
        }
        return dp[i][n]=cnt;
    }
};










