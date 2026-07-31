class Solution {
public:
    int minimumPushes(string word) {
        // all letter are distinct 
        int n=word.size();
        // unordered_map<char,int>mp;
        // for(auto ch:word) mp[ch]++;

        // vector<int>fre;
        // for(auto [key,f]:mp) fre.push_back(f);

        // sort(fre.rbegin(), fre.rend());
        int cnt=0;
        int ans=0;
        for(int i=0; i<word.size(); i++){
            int x=cnt/8;
            // ans= ans+(x+1)*fre[i];
            ans= ans+(x+1);
            cnt++;
        }
        return ans;
    }
};