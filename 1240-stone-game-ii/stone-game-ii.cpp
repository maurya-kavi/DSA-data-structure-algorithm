class Solution {
public:
int n;
int dp[2][101][101];
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        // we jut need for the alice so we maintain hte status of whom function call is,
        memset(dp,-1,sizeof(dp));
        return solve(piles,1,0,1);
    }

    int solve(vector<int>&nums, int alice, int i, int M){
        
if(i>=n) return 0;

int res=(alice==1)? -1:INT_MAX;

if(dp[alice][i][M]!=-1) return dp[alice][i][M];

        int stones=0;
        for(int x=1; x<=min(2*M, n-i); x++){
            int ind=i+x-1;
            stones+=nums[ind];

            if(alice==1){
                res=max(res, stones+solve(nums, 0, i+x, max(x,M) ));
            }else{
                res=min(res, solve(nums, 1, i+x, max(x,M)));
            }
        }

        return dp[alice][i][M]=res;
    }
};