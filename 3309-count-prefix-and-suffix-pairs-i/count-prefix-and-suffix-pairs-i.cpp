class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        if(n<=1) return 0;
        int ans=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(words[j].size()>=words[i].size() && isPrefixAndSuffix(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
    bool isPrefixAndSuffix(string &s, string &t){
        // check is string s is prefix and suffix of string t
        bool flag=true;
        // check for prefix
        for(int i=0; i<s.size(); i++){
            if(s[i]!=t[i]) {
                flag=false;
                break;
            }
        }
        if(!flag) return false;

        int m=t.size();
        int j=m-1;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]!=t[j]){
                flag=false;
                break;
            }
            j--;
        }

        return flag;
    }
};