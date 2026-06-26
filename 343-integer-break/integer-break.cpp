class Solution {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        if(n==4) return 4;

        return solve(n);
    }

    int solve(int n){
        if(n<=4) return n;

        return 3*solve(n-3);
    }
};