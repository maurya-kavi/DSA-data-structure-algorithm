class Solution {
public:
int dp[101];
    int numDecodings(string s) {
        int n=s.size();
        string temp="";
        memset(dp,-1,sizeof(dp));
        return rec(0,s,temp);
    }

    int rec(int i, string &s, string temp){

        if(temp.size()==1 && temp[0]=='0') return 0;
        if(temp.size()==2 && (temp[0]=='0' || stoi(temp)>26)) return 0;
        if(i==s.size()) return 1;

        if(dp[i]!=-1) return dp[i];
        int a1=rec(i+1,s,string(1,s[i]));
        int a2=0;
        if(i+1<s.size()) a2=rec(i+2, s,string(1, s[i]) + s[i + 1]);

        return dp[i]=a1+a2;
    }
};











