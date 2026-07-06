class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(),comp);

        int cnt=1;

        int s=intervals[0][0], e=intervals[0][1];
        for(int i=1; i<n; i++){
            int ss=intervals[i][0];
            int ee=intervals[i][1];

            if(ss>=s && ee<=e){
                continue;
            }
            else{
                cnt++;
                s=ss;
                e=ee;
            }
        }
        return cnt;
    }

    static bool comp(const vector<int>&a, const vector<int>&b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    }
};