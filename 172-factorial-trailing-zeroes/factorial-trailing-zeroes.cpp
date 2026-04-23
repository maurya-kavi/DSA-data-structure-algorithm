class Solution {
public:
    int trailingZeroes(int n) {
        int TrailingZeros=0;
        while(n>0){
            TrailingZeros+=n/5;
            n/=5;
        }
        return TrailingZeros;
    }
};