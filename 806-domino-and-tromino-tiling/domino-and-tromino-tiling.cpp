class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        
        long long MOD = 1e9 + 7;
        
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        for (int i = 4; i <= n; i++) {
            // Master Recurrence: F(i) = 2*F(i-1) + F(i-3)
            dp[i] = (2 * dp[i-1] % MOD + dp[i-3] % MOD) % MOD;
        }
        
        return dp[n];
    }
};

// explanation
/*
F_i = F_{i-1} + F_{i-2} + P_{i-1}, F_{i-1} = F_{i-2} + F_{i-3} + P_{i-2}. 
Subtract the second equation from the first: F_i - F_{i-1} = F_{i-1} - F_{i-3} + (P_{i-1} - P_{i-2}). Now, look at Equation 2: P_i = P_{i-1} + 2F_{i-2} .If we rearrange this, we get: 
P_{i-1} - P_{i-2} = 2F_{i-3}.Substitute that beautiful realization into our subtracted equation:F_i - F_{i-1} = F_{i-1} - F_{i-3} + 2F_{i-3} , F_i - F_{i-1} = F_{i-1} + F_{i-3 .Move F_{i-1} to the other side, and we get the master recurrence: 
F_i = 2F_{i-1} + F_{i-3} -- and this is the final recurence equation to solve the question , 
*/