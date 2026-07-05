class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        vector<vector<int>> maxScore(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));
        
        maxScore[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;
        
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || (r == n - 1 && c == n - 1)) continue;
                
                int currentCellScore = (board[r][c] == 'E') ? 0 : board[r][c] - '0';
                int localMax = -1;
                
                if (r + 1 < n && maxScore[r+1][c] != -1) {
                    localMax = max(localMax, maxScore[r+1][c]);
                }
                if (c + 1 < n && maxScore[r][c+1] != -1) {
                    localMax = max(localMax, maxScore[r][c+1]);
                }
                if (r + 1 < n && c + 1 < n && maxScore[r+1][c+1] != -1) {
                    localMax = max(localMax, maxScore[r+1][c+1]);
                }
                
                if (localMax != -1) {
                    maxScore[r][c] = localMax + currentCellScore;
                    long long currentWays = 0;
                    
                    if (r + 1 < n && maxScore[r+1][c] == localMax) 
                        currentWays = (currentWays + ways[r+1][c]) % MOD;
                    if (c + 1 < n && maxScore[r][c+1] == localMax) 
                        currentWays = (currentWays + ways[r][c+1]) % MOD;
                    if (r + 1 < n && c + 1 < n && maxScore[r+1][c+1] == localMax) 
                        currentWays = (currentWays + ways[r+1][c+1]) % MOD;
                        
                    ways[r][c] = currentWays;
                }
            }
        }
        
        if (maxScore[0][0] == -1) {
            return {0, 0};
        }
        
        return {maxScore[0][0], ways[0][0]};
    }
};