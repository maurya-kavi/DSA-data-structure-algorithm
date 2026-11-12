class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char ch:s) mp[ch]++;
        bool odd=false;
        int ans=0;
        for(auto [key,freq]:mp){
            if(freq&1){
                //odd
                odd=true;
            }
            ans+=(freq/2);
        }
        ans*=2;
        if(odd) ans++;
        return ans;
    }
};