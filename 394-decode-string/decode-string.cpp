class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<int>cntSt;
        stack<string>stringSt;

int currNum=0;
string currStr="";

        for(char c:s){
            if(isdigit(c)){
                currNum=currNum*10 +(c-'0');
            }
            else if(c=='['){
                cntSt.push(currNum);
                stringSt.push(currStr);

                currNum=0;
                currStr="";
            }
            else if(c==']'){
                int fr=cntSt.top();
                cntSt.pop();
                string decoded=stringSt.top();
                stringSt.pop();

                for(int i=0; i<fr; i++){
                    decoded+=currStr;
                }

                currStr=decoded;
            }
            else{
                currStr+=c;
            }
        }
        return currStr;
    }
};