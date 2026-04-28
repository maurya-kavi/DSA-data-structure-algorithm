class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
             [](const auto &a, const auto &b) {
                 return a[1] < b[1]; // sort by end time
             });

        int count = 1; // we take first interval
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEnd) {
                count++;
                lastEnd = intervals[i][1];
            }
        }

        return n - count;
    }
};