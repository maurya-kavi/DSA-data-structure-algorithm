class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        int l=0, r=0;
        unordered_map<char,int>mp;
        int mx_freq=0;
        while(r<n){
            mp[s[r]]++;
            mx_freq=max(mx_freq, mp[s[r]]);
            if((r-l+1)-mx_freq > k){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        // we are considering the current historical mx_freq and not updating for every window means we are forcing the algo to maintain the hostory max_len(ans) can be not look for the smaller valid window
        return ans;
    }
};