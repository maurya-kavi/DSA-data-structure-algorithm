class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        unordered_map<char,int>mp;
        mp['b']=0;
        mp['a']=0;
        mp['l']=0;
        mp['o']=0;
        mp['n']=0;
        for(char ch:text) {
            if(ch=='b' || ch=='a' || ch=='l' || ch=='o' || ch=='n') mp[ch]++;
        }
        int ans=INT_MAX;
        ans=min(mp['b'],ans);
        ans=min(ans,mp['a']);
        ans=min(ans,mp['l']/2);
        ans=min(ans,mp['o']/2);
        ans=min(ans,mp['n']);
        
        return ans;
    }
};