class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int l=0, r=n-1;
        int op=0, clfromend=0;
        int cnt=0;
        while(l<r){
            if(s[l]=='[') op++;
            else op--;

            if(op<0){
                while(l<r && s[r]==']') {r--; clfromend++;}
                if(l<r){
                    swap(s[l],s[r]);
                    cnt++;
                    l++; r--;
                    clfromend++;
                    while(l<r && s[r]=='[' && clfromend>0) {r--; clfromend--;}
                    op+=2;
                }
            }else l++;
        }
        
        return cnt;
    }
};