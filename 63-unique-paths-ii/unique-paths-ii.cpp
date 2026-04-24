class Solution {
public:
//tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));

        if(obstacleGrid[0][0]==1) return 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0 && obstacleGrid[i][j]!=1){
                    dp[0][0]=1;
                    continue;
                }
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                int top=0;
                int left=0;

                if(i>0 && obstacleGrid[i][j]!=1) top=dp[i-1][j];
                if(j>0 && obstacleGrid[i][j]!=1) left=dp[i][j-1];

                dp[i][j]=top+left;
            }
        }
        return dp[m-1][n-1];
    }
};