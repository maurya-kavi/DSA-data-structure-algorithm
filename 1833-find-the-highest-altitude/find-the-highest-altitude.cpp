class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int prev=0;
        int ans=0; // trip starts from 0 altitude
        for(int i=0; i<n; i++){
            prev=prev+gain[i];
            ans=max(ans,prev);
        }
        return ans;
    }
};