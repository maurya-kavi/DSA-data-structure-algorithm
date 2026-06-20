class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        int m=pattern.size();
        int ans=0;
        if(n<=m) return 0;
        //saare m+1 len ke subarray ke liye check kar lo......
        for(int i=0; i<(n-m); i++){
            int ii=i;
            bool flag=true;
            for(int j=0; j<m; j++){
                if(pattern[j]==1){
                    if(nums[ii+1]<=nums[ii]) {
                        flag=false;
                        break;
                    }
                }
                else if(pattern[j]==0){
                    if(nums[ii+1]!=nums[ii]) {
                        flag=false;
                        break;
                    }
                }else{
                    if(nums[ii+1]>=nums[ii]){
                        flag=false;
                        break;
                    }
                }
                ii++;
            }
            if(flag) ans++;
        }
        return ans;
    }
};