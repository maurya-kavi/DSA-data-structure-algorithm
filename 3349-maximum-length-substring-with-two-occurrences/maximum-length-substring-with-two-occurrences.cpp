class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int ans=0;
        int i=0;
        int j=0;
        while(i<n){
            if(!mp.count(s[i]) || mp[s[i]]<2){
                ans=max(ans, i-j+1);
                mp[s[i]]++;
                i++;
            }else{
                // mp[s[i]]==2;
                while(j<n && s[j]!=s[i]){
                    mp[s[j]]--;
                    j++;
                }
                j++;
                ans=max(ans, i-j+1);
                i++;
            }
        }
        return ans;
    }
};