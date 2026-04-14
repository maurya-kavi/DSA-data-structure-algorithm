class Solution {
public:
    bool isSubsequence(string s, string t) {
        // have to find the s in t
        
        int n=s.size();
        int m=t.size();
        if(n==0) return true;
        int j=0;
        for(int i=0; i<m; i++){
            if(t[i]==s[j]){
                j++;
            }
            if(j==n) return true;
        }
        return false;
    }
};