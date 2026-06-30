class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        string s=preorder;

        stack<string>st;
        int i=n-1;
        if(n==3) return false; // 2 node , 1 commas
        if(n==1 && s[i]!='#') return false;
        if(n==1 && s[i]=='#') return true;

        if(s[n-1]!='#' && s[n-3]!='#') return false;

        st.push(string(1,'#'));
        st.push(string(1,'#'));
        i-=4;

        while(i>=0){
            if(s[i]!='#'){
                if(st.size()<2) return false;
                string val="";
                while(i>=0 && s[i]!=','){
                    val+=s[i];
                    i--;
                }
                st.pop();
                st.pop();
                st.push(val);
                i--;
            }else{
                st.push(string(1,'#'));
                i-=2;
            }
        }

        if(st.size()==1) return true;
        else return false;
    }
};