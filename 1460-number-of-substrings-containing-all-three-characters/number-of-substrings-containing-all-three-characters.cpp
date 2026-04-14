class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0;
        int res=0;
        unordered_map<char,int>mp;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        for(int r=0; r<n; r++){
            if(s[r]=='a' || s[r]=='b' || s[r]=='c')  mp[s[r]]++;

            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                int extra=(n-1)-r;
                res+=(1+extra);
                
                if(s[l]=='a' || s[l]=='b' || s[l]=='c') mp[s[l]]--;

                l++;
            }
        }
        return res;
    }
};