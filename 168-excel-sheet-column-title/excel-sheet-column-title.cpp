class Solution {
public:
    string convertToTitle(int columnNumber) {
        string t="";
        int n=columnNumber;
        while(n>0){
            n--;
            int rem=n%26;
            if(rem<0) rem+=26;
            char ch='A'+rem;
            t+=(ch);
            n/=26;
        }
        reverse(t.begin(),t.end());
        return t;
    }
};