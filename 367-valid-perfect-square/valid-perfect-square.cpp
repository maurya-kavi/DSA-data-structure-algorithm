class Solution {
public:
    bool isPerfectSquare(int num) {
        int x=sqrt(num);
        if(num==x*x) return true;
        return false;
    }
};