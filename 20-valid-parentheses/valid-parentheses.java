class Solution {
    public boolean isValid(String s) {
        Stack<Character>st=new Stack();
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='['){
                //opening
                st.push(s.charAt(i));
            }else{
                char ch=s.charAt(i);
                if(st.empty()) return false;
                if(ch==')'){
                    if(st.peek()!='(') return false;
                    else st.pop();
                }
                else if(ch=='}'){
                    if(st.peek()!='{') return false;
                    else st.pop();
                }
                else if(ch==']'){
                    if(st.peek()!='[') return false;
                    else st.pop();
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
}