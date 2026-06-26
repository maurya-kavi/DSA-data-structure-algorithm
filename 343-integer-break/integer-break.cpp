class Solution {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        if(n==4) return 4;

        int cnt3=0;
        while(n>4){
            n-=3;
            cnt3++;
        }
        return n*pow(3,cnt3);
    }
};