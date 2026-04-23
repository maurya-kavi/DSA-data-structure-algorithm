class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int val=digits[n-1] + 1;
        int r=val%10;
        int q=val/10;
        digits[n-1]=r;
        for(int i=n-2; i>=0; i--){
            int vall=digits[i]+q;
            r=vall%10;
            q=vall/10;
            digits[i]=r;
        }
        if(q>0) digits.insert(digits.begin(),q);
        return digits;
    }
};