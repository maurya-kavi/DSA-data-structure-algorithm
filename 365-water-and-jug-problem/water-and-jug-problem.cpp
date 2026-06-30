class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target>(x+y)) return false;
        int gcdd=gcd(x,y);
        return target%gcdd==0;
    }
};