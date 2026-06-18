class Solution {
public:
int dp[505][27][505];
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(nums,n,k,0,0);
    }
    int rec(vector<int>&nums, int &n, int k, int ind, int prev){
        if(ind==n){
            return 0;
        }
        if(dp[ind][k][prev]!=-1) return dp[ind][k][prev];
        int ans=0;
        if((prev!=0 && nums[ind]==nums[prev-1]) || prev==0){
            ans=max(ans,1+rec(nums,n,k,ind+1,ind+1));
        }else{
            if(k>0){
                ans=max(ans,1+rec(nums,n,k-1,ind+1,ind+1));
            }
        }
        dp[ind][k][prev]=ans=max(ans, rec(nums,n,k,ind+1,prev));
        return ans;
    }
};