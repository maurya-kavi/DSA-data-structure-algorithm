class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        string t="";

        int op=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') {op++; t+='(';}
            else if(s[i]==')'){
                if(op>0){
                    op--;
                    t+=')';
                }else{
                    continue;
                }
            }else{
                t+=s[i];
            }
        }

        //remove extra opening , from the end of the string t
        string ans="";
        for(int i=t.size()-1; i>=0; i--){
            if(t[i]=='(' && op>0) {op--; continue;}
            else ans+=t[i];
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};