class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n>0){
            int rem=n%2;
            n/=2;
            if(rem==1) cnt++;
        }
        return cnt;
    }
};