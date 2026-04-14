class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int n=strs.size();
        int mn=INT_MAX;
        for(int i=0; i<n; i++){
            int x=strs[i].length();
            mn=min(mn,x);
        }
        for(int i=0; i<mn; i++){
            char ch=strs[0][i];
            bool t=true;
            for(int j=0; j<n; j++){
                if(strs[j][i]!=ch) {t=false; break;}
            }
            if(t) s+=ch;
            else break;
        }
        return s;
    }
};