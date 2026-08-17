class Solution {
public:


    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        vector<int>pre(n,0);
        for(int i=0; i<n; i++){
            pre[i]=stoneValue[i]+(i>0 ? pre[i-1]:0);
        }

        for(int l=n-1; l>=0; l--){
            for(int r=l+1; r<n; r++){
                for(int mid=l; mid<r; mid++){
                    int left=pre[mid]-(l>0? pre[l-1]:0);
                    int right=pre[r]-pre[mid];

                    if(left<right){
                        dp[l][r]=max(dp[l][r], left+dp[l][mid]);
                    }
                    else if(left>right){
                        dp[l][r]=max(dp[l][r], right+dp[mid+1][r]);
                    }
                    else{
                        dp[l][r]=max({dp[l][r], left+dp[l][mid], right+dp[mid+1][r]});
                    }
                }

            }
        }

        return dp[0][n-1];
    }

//     int solve(int l, int r, vector<int>&pre){
//         if(l>=r) return 0; // alice koi element nhi le payega

// if(dp[l][r]!=-1) return dp[l][r];

// int score=0;
//         for(int mid=l; mid<r; mid++){
//             int left=pre[mid]-(l>0? pre[l-1]:0);
//             int right=pre[r]-pre[mid];

//             if(left<right){
//                 score=max(score,left+solve(l,mid,pre));
//             }
//             else if(left>right){
//                 score=max(score,right+solve(mid+1,r,pre));
//             }else{
//                 score=max({score,left+solve(l,mid,pre), right+solve(mid+1,r,pre)});
//             }
//         }

//         return dp[l][r]=score;
//     }
};



