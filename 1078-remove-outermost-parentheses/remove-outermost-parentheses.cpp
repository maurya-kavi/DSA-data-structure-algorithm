class Solution {
public:
    string removeOuterParentheses(string s) {
        if(s.size()<=2) return "";
        unordered_set<int>st;
        // st.insert(0);
        int n=s.size();
        int op=0,cl=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') op++;
            else cl++;

            if(op-cl==1 && cl==0){
                st.insert(i);
            }

            if(op==cl){
                st.insert(i);
                op=0;
                cl=0;
        }
        }

        string t="";
        for(int i=0; i<n; i++){
            if(!st.count(i)){
                t+=s[i];
            }
        }

        return t;
        
    }
};