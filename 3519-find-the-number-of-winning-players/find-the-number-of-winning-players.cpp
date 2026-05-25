class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int m=pick.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0; i<m; i++){
            int ind=pick[i][0];
            int ball=pick[i][1];
            mp[ind].push_back(ball);
        }
        int ans=0;
        for(auto [key,arr]:mp){
            sort(arr.begin(),arr.end());
            int mxcnt=1, cnt=1;
            for(int i=1; i<arr.size(); i++){
                if(arr[i]==arr[i-1]){
                    cnt++;
                    mxcnt=max(cnt, mxcnt);
                }else{
                    cnt=1;
                }
            }
            if(mxcnt>key) ans++;
        }
        return ans;
    }
};