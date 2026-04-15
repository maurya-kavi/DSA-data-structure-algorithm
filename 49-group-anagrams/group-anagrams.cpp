class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mpp;

        for(string& s:strs){
            string key=s;
            sort(key.begin(), key.end());
            mpp[key].push_back(s); // key will be soted word and value contain all the anagrams
        }

        vector<vector<string>>ans;
        for(auto& pair:mpp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
