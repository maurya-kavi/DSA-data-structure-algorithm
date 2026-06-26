class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0, r=s.size()-1;
        int mid=l+(r-l)/2;
        for(int i=0; i<=mid; i++) swap(s[i],s[r-i]);
    }
};