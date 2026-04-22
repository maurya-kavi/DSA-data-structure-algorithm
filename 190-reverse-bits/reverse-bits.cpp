class Solution {
public:
    int reverseBits(int n) {
        int result=0;

        for(int i=0; i<32; i++){
            result=result<<1; // make the rightmost digit zero

            int lastbit=n&1;

            result=result|lastbit;

            n=n>>1; //shift to second rightmost bit
        }
        return result;
    }
};