class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(int i=0; i<n; i++){
            if(nums[i]>0) s.insert(nums[i]);
        }
        int ans=-1;
        int i=1;
        int lastval=0;
        for(auto val:s){
            if(val!=i) return i;
            i++;
            lastval=val;
        }
        return (lastval+1);
    }
};