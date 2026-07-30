class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map<char,int>mp;
        for(auto ch:word) mp[ch]++;

        vector<int>fre;
        for(auto [key,f]:mp) fre.push_back(f);

        sort(fre.begin(), fre.end());
        int cnt=0;
        int ans=0;
        for(int i=0; i<fre.size(); i++){
            int x=cnt/8;
            ans= ans+(x+1)*fre[i];
            cnt++;
        }
        return ans;
    }
};