class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string t="";
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]==' '){
                reverse(t.begin(),t.end());
                ans+=t;
                if(!t.empty()) ans+=" ";
                t="";
            }else{
                t+=s[i];

            }
            
        }
        
        reverse(t.begin(),t.end());
        ans+=t;
        t="";
        for(int i=ans.size()-1; i>=0; i--){
            if(ans[i]==' ') ans.pop_back();
            else break;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};