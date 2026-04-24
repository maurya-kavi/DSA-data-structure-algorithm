class Solution {
public:
//memoization
    int rec(int i, int j,vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        if(i==0 && j==0 && obstacleGrid[i][j]!=1) return 1;
        if(i<0 || j<0 || obstacleGrid[i][j]==1 ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int top=rec(i-1,j,obstacleGrid,dp);
        int up=rec(i,j-1,obstacleGrid,dp);

        return dp[i][j]=top+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return rec(m-1,n-1,obstacleGrid, dp);
    }
};