class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<pair<int,int>>dp(n);
        for(int i=0; i<n; i++) dp[i]={1,-1};

        int mxi=0;
        int mxseq=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i].first<1+dp[j].first){
                        dp[i].first=1+dp[j].first;
                        dp[i].second=j;
                    }
                }
            }
            if(dp[i].first>mxseq){
                mxseq=dp[i].first;
                mxi=i;
            }
        }


        vector<int>ans;

        while(mxi!=-1){
            ans.push_back(nums[mxi]);
            mxi=dp[mxi].second;
        }

        return ans;
    }
};