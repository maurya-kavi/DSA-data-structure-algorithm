class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int cnt=0;
        int op=0; //opening
        for(int i=0; i<n; i++){
            if(s[i]=='(') op++;
            else{
                if(op>0) op--;
                else cnt++;
            }
        }
        cnt+=op;
        return cnt;
    }
};