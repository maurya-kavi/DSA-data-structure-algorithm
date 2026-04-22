class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift_cnt=0;
        //until prefix of left and right became equal
        while(left<right){
            left>>=1; //right shift of left by 1
            right>>=1; //right shift of right by 1
            shift_cnt++;
        }
        return left<<shift_cnt;
    }
};