class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(auto ch:s){
            if(isdigit(ch)){
                ans.pop_back();
            }else{
                ans+=ch;
            }
        }
        return ans;
    }
};