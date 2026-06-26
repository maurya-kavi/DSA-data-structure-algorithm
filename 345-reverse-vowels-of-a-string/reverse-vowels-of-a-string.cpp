class Solution {
public:
    string reverseVowels(string s) {
        int i=0, r=s.size()-1;
        while(i<=r){
            while(i<=r && (check(s[i])==false)) i++;
            while(i<=r && (check(s[r])==false)) r--;

            if(i<=r) swap(s[i],s[r]);
            i++;
            r--;
        }
        return s;
    }

    bool check(char ch){
        if(ch=='a' || ch=='o' || ch=='e' || ch=='i' || ch=='u' ||  ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
        return false;
    }
};