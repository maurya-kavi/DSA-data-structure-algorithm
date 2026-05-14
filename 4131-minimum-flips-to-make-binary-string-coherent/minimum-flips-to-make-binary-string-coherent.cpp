class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int cnt1=0, cnt0=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0') cnt0++;
            else cnt1++;
        }
        if(cnt1<=1 || cnt0==n || cnt0==0 ) return 0;
        else {
            if(s[0]=='1' && s[n-1]=='1'){
                if(cnt1==2) return 0;
                else return min(cnt1-2,cnt0);
            }else{
                return min(cnt0,cnt1-1);
            }
        }
    }
};