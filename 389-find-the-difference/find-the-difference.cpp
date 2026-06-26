class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(auto &ch:s) mp1[ch]++;
        for(auto &ch:t) mp2[ch]++;

        for(auto ch:t){
            if(mp2[ch]==mp1[ch]) continue;
            else return ch;
        }

        return 'a';
    }
};