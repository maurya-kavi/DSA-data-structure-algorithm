class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>mp;
        for(int i=0; i<n; i++) mp[s[i]]++;
        for(int i=0; i<m; i++) {
            auto it=mp.find(t[i]);
            if(it==mp.end()) return false;
            int cnt=mp[t[i]];
            if(cnt<=0) return false;
            mp[t[i]]--;
        }
        for(auto [key,val]:mp){
            if(val!=0) return false;
        }
        return true;
    }
};