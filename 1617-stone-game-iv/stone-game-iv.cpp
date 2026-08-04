class Solution {
public:
// recursion + memoization
vector<int>dp;
    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }

    bool solve(int n){
        if(n==0) return false;

        if(dp[n]!=-1) return dp[n]==1;

        for(int i=1; i*i<=n; i++){
            // Agar ek bhi move samne wale ko losing state mein daal de
            if(solve(n-i*i)==false){
                dp[n]=1; // current player jeet gya
                return true;
            }
        }

        // Agar koi bhi move se samne wala nahi haarta, toh current player haar jayega
        dp[n] = 0;
        return false;

    }
};