class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();
        int m=s.size();
        unordered_map<char,string>mp;
        unordered_map<string,char>mp2;
        int j=0;
        vector<string>v;
        int k=0;
        for(int i=0; i<m; i++){
            if(s[i]!=' ') {k=i; break;}
        }
        string p="";
        while(k<m){
            if(s[k]==' '){
                v.push_back(p);
                k++;
                p="";
                while(s[k]==' ') k++;
            }else{ p+=s[k]; k++;}
        }
        if(p!="") v.push_back(p);

        if(v.size()!=n) return false;

        for(int i=0; i<n; i++){

            if(mp.count(pattern[i])){
                if(mp[pattern[i]]!=v[i]) return false;
               
            }
            else if(mp2.count(v[i])){
                if(mp2[v[i]]!=pattern[i]) return false;
            }
            else{
                mp[pattern[i]]=v[i];
                mp2[v[i]]=pattern[i];
            }
        }
        return true;
    }
};