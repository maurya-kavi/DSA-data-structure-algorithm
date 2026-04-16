class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int m=intervals[0].size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0];
        int mx=intervals[0][1];
        for(int i=0; i<n-1; i++){
            if(mx>=intervals[i+1][0]) {
                mx=max(mx,intervals[i+1][1]);
                continue;
            }
            ans.push_back({s,mx});
            s=intervals[i+1][0];
            mx=intervals[i+1][1];
        }
        ans.push_back({s,mx});
        return ans;
    }
};