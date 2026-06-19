class Solution {
public:
#define ll long long
    string longestDupSubstring(string s) {
        int n=s.size();
        int l=1, r=n-1;
        string ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            string t=possible(s,mid);
            if(t!="."){
                ans=t;
                l=mid+1;
            }else r=mid-1;
        }
        return ans;
    }
    // rolling hash technique
    string possible(string &s, int &mid){
        ll p = 31;
        ll m = 1e9 + 7;
        ll hp = 1;
        
        for (int i = 0; i < mid - 1; i++) {
            hp = (hp * p) % m;
        }
        
        ll hashVal = 0;
        for (int i = 0; i < mid; i++) {
            hashVal = (hashVal * p + (s[i] - 'a' + 1)) % m;
        }
        
        unordered_map<ll, vector<int>> store_occ;
        store_occ[hashVal].push_back(0);

        for (int i = mid; i < s.size(); i++) {
            hashVal = (hashVal - (s[i - mid] - 'a' + 1) * hp % m + m) % m;
            hashVal = (hashVal * p + (s[i] - 'a' + 1)) % m;
            
            int curr_start = i - mid + 1;
            
            if (store_occ.count(hashVal)) {
                for (int start_idx : store_occ[hashVal]) {
                    bool match = true;
                    for (int j = 0; j < mid; j++) {
                        if (s[start_idx + j] != s[curr_start + j]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        return s.substr(curr_start, mid);
                    }
                }
            }
            store_occ[hashVal].push_back(curr_start);
        }
        return ".";
    }
};

