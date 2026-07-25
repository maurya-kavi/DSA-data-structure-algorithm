class Solution {
public:
    int maxProduct(int n) {
        int mx=0,smx=0;
        while(n>0){
            int d=n%10;
            if(d>mx){
                smx=mx;
                mx=d;
            }
            else if(d>smx) smx=d;

            n/=10;
        }

        return mx*smx;
    }
};