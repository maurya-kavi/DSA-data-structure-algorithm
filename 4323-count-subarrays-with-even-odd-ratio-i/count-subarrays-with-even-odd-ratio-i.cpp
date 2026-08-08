class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int valid=0;
        for(int i=0; i<n; i++){
            int cntO=0, cntE=0;
            for(int j=i; j<n; j++){
                if(nums[j]%2==0) cntE++;
                else cntO++;

                if(cntO>0 && (float)cntE/cntO <= (float)a/b) valid++;
            }
        }
        return valid;
    }
};