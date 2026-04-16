class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(tokens[i]!="+" && tokens[i]!="*" && tokens[i]!="/" && tokens[i]!="-"){
                st.push(stoi(tokens[i]));
                continue;
            }else{
                if(st.size()>1){
                    int first=st.top();
                    st.pop();
                    int second=st.top();
                    st.pop();
                
                    if (tokens[i] == "+") st.push(second + first);
                    else if (tokens[i] == "-") st.push(second - first);
                    else if (tokens[i] == "*") st.push(second * first);
                    else if (tokens[i] == "/") st.push(second / first);
                }
            }
        }
        return st.top();
    }
};