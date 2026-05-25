class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int n=words.size();
        int m=licensePlate.size();
        string ans;
        unordered_map<char,int>mp;
        for(char ch:licensePlate){
            char x=tolower(ch);
            if(x>='a' && x<='z'){
                mp[x]++;
            }
        }
        int sz=mp.size();
        for(int i=0; i<n; i++){
            int cnt=0;
            string t=words[i];
            unordered_map<char,int>mpp;
            for(auto ch:t){
                mpp[ch]++;
            }
            for(auto [key,fre]:mp){
                if(mpp.find(key)==mpp.end()) break;
                if(mpp[key]<fre) break;
                cnt++;
            }
            if(cnt==sz){
                if(ans.size()==0 || (t.size()<ans.size())){
                    ans=t;
                }
            }
        }
        return ans;
    }
};