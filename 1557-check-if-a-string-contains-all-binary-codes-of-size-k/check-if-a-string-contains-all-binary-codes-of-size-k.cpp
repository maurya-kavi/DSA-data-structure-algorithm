class Solution {
public:
#define ll long long
    bool hasAllCodes(string s, int k) {
        if(s.size()<k) return false;
        ll tot=pow(2,k);
        unordered_set<ll>st;
        ll p=2; // base prime
        ll m=1e15+7; // mod
        ll hp=1; // highest power
        // initiating........
        ll hashVal=0;
        // hp=p^(k-1)
        for(int i=0; i<k-1; i++){
            hp=(hp*p)%m;
        }

        // first window hashval
        for(int i=0; i<k; i++){
            hashVal=(hashVal*p + (s[i]-'0'))%m;
        }
        st.insert(hashVal);

        for(int i=k; i<s.size(); i++){
            hashVal=(hashVal- (s[i-k]-'0')*hp%m +m)%m;
            hashVal=((hashVal*p)%m + (s[i]-'0'))%m;
            st.insert(hashVal);
        }

        if(st.size()!=tot) return false;
        return true;
    }
};