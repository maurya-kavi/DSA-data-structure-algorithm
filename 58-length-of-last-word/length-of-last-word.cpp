class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i;
        for(i=n-1; i>=0; i--){
            if(s[i]!=' ') break;
        }
        int len=0;
        for(int j=i; j>=0 && s[j]!=' '; j--){
            len++;
        }
        return len;
    }
};