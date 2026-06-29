class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int cnt=0;
        for(string &s:patterns){
            if(word.contains(s)) cnt++;
        }
        return cnt;
    }
};