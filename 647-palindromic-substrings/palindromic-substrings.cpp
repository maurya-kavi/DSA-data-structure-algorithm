class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                bool found=true;
                int l=i, r=j;
                while(l<=r){
                    if(s[l]!=s[r]){ found=false; break;}
                    l++;
                    r--;
                }
                if(found) cnt++;
            }
        }
        return cnt;
    }
};