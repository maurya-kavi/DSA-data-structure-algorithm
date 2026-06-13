class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto s:words){
            int sum=0;
            for(auto ch:s){
                int i=ch-'a';
                sum+=weights[i];
            }
            sum=sum%26; // from left (a)
            sum=26-sum-1; // from right (z)
            char c='a'+sum;
            ans+=c;

        }
        return ans;
    }
};