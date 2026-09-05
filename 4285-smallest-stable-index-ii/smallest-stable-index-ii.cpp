class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<int>premx(n);
        
        for(int i=0; i<n; i++){
            if(i==0) premx[i]=nums[i];
            else premx[i]=max(premx[i-1],nums[i]);
        }
        
        vector<int>sufmn(n);
        
        for(int i=n-1; i>=0; i--){
            if(i==(n-1)) sufmn[i]=nums[i];
            else sufmn[i]=min(sufmn[i+1],nums[i]);
        }
        
        for(int i=0; i<n; i++){
            int val=premx[i]-sufmn[i];
            if(val<=k) return i;
        }
        return -1;
    }
};