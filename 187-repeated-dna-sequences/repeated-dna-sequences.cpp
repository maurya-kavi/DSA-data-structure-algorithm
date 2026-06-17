class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        unordered_map<string,int>mp;
        vector<string>result;
        if(n<=10) return result;
        for(int i=0; i<=(n-10); i++){
            string substring=s.substr(i,10);
            if(mp[substring]==1){
                result.push_back(substring);
            }
            mp[substring]++;
        }
        return result;
        
    }
};



















