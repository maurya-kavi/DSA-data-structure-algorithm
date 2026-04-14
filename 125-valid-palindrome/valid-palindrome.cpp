class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string t="";
        for(auto ch:s){
            char c=tolower(ch);
            if((c>='a' && c<='z' ) || (c>='0' && c<='9')){
                t+=c;
            }
        }
        string p=t;
        reverse(p.begin(),p.end());
        if(t==p) return true;
        return false;
    }
};