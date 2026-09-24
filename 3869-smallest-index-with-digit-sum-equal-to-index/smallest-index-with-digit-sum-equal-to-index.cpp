class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        // int mnsum=INT_MAX;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum=0;
            int x=nums[i];
            while(x>0){
                sum+=(x%10);
                x/=10;
            }
            if(sum==i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};