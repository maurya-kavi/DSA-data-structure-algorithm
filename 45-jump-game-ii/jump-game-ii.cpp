class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int end=0,steps=0,far=0;
        if(n==1) return 0;
        for(int i=0; i<n-1; i++){
            far=max(far,nums[i]+i);
            if(far>=n-1) return steps+1;

            if(end==i){
                end=far;
                steps++;
            }
        }
        return  steps;
    }
};