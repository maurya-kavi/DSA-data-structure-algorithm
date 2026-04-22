class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int n=right;
        while(n>0 && n>left){
            n=(n&(n-1));
        }
        return n;
    }
};