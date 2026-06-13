class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>last_occ(26,0);
        vector<bool>vis(26,false);
        string r="";

        for(int i=0; i<n; i++){
            last_occ[s[i]-'a']=i;
        }

        for(int i=0; i<n; i++){
            char ch=s[i];

            if(vis[ch-'a']) continue;

            while(!r.empty() && r.back()>ch && last_occ[r.back()-'a']>i){
                vis[r.back()-'a']=false;
                r.pop_back();
            }
            r.push_back(ch);
            vis[ch-'a']=true;
        }
        return r;
    }
};