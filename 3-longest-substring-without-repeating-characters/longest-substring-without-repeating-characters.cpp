class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,pair<int,int>>mp; // {char,{freq,ind}}
        int mxs=0;
        int l=0, r=0;
        while(l<=r && r<n){
            if(mp.find(s[r])!=mp.end()){
                int ind=mp[s[r]].second;
                while(l<=ind){
                    mp.erase(s[l]);
                    l++;
                }
            }
            mp[s[r]]={1,r};
            mxs=max(mxs,r-l+1);
            r++;
        }
        return mxs;
    }
};