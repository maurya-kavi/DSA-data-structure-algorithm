class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        bool a=false, b=false, c=false;
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(s[j]=='a') a=true;
                if(s[j]=='b') b=true;
                if(s[j]=='c') c=true;
                if(a && b && c){
                    int extra=(n-1)-j;
                    ans+=(1+extra);
                    break;
                }
            }
            a=false,b=false,c=false;
        }
        return ans;
    }
};