class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto ch:s) mp[ch]++;
int oddcntfreq=0;
vector<char>v;
        for(auto [key,val]:mp){
            if(val&1) oddcntfreq++;
            v.push_back(key);
        }

        if(oddcntfreq>1) return "";

        sort(v.begin(),v.end());

string p="", q="";
        string res="";
        char oddwala='a';
        for(int i=0; i<v.size(); i++){
            if(mp[v[i]]&1){
                p+=string(mp[v[i]]/2,v[i]);
                oddwala=v[i];
                q+=string(mp[v[i]]/2,v[i]);
            }
            else{
                p+=string(mp[v[i]]/2,v[i]);
                q+=string(mp[v[i]]/2,v[i]);
            }
        }
        if(oddcntfreq==1) p+=oddwala;
        reverse(q.begin(),q.end());
        res+= p;
        res+=q;
        return res;
    }
};