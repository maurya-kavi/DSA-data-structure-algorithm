class Solution {
public:
#define ll long long
    char processStr(string s, long long k) {
        ll l=0;
        ll n=s.size();
        for(int i=0; i<n; i++){
            if(isalpha(s[i])){ 
                l++;
            }
            else if(s[i]=='#') l*=2;
            else if(s[i]=='*') {
                if(l>0) l--;
            }
            else if(s[i]=='%') continue;
        }

        if(l<=(k)) return '.';

        for(int i=n-1; i>=0; i--){
            if(isalpha(s[i])) l--;
            else if(s[i]=='#') {
                l=l/2;
                if(k>=l) k=k-l;
            }
            else if(s[i]=='%'){
                k=l-k-1;
            }
            else if(s[i]=='*') {
                l++;
            }

            if(k==l) return s[i];
        }
        return '.';
    }
};

/*
approach:
#-> l=l/2, k=k-l/2
'a' to 'z' -> l--;
% -> k=l-k-1; l no change
* -> l--, k no change
*/








