class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);
        vector<int>p=arr;
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
unordered_map<int,int>mp;
        int i=1;
        for(int &val:p){
            mp[val]=i;
            i++;
        }

        for(int i=0; i<n; i++){
            ans[i]=mp[arr[i]];
        }

        return ans;
    }
};