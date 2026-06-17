class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s.compare(0,n-i,rev,i,n-i)==0) return rev.substr(0,i)+s;
        }
        return rev+s;
    }
};






