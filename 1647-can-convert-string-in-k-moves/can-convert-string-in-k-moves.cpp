class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n=s.size(), m=t.size();
        if(n!=m) return false;

        vector<int>cnt(27,0); // how many times i (diff) is seen 

        for(int i=0; i<n; i++){
            if(s[i]==t[i]) continue;

                long long x=(t[i]-s[i]+26 )%26;;
                long long y=1LL*26*cnt[x] +x;
                if(y>k) return false; 
            
            cnt[x]++;
        }

        return true;
    }
};







