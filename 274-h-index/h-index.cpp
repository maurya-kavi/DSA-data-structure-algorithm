class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.rbegin(),citations.rend());
        // int i=1;
        int j=0;
        for(j=0; j<n; j++){
            if(citations[j]<(j+1)) break;
        }
        return j;
    }
};