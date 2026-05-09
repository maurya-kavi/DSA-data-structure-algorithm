class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>preEven(n,0), preOdd(n,0);
        if(nums[n-1]&1) preOdd[n-1]++;
        else preEven[n-1]++;

        for(int i=n-2; i>=0; i--){
            if(nums[i]&1){
                preOdd[i]=preOdd[i+1]+1;
            }else preOdd[i]=preOdd[i+1];

            if(nums[i]%2==0){
                preEven[i]=preEven[i+1]+1;
            }else preEven[i]=preEven[i+1];
        }

        vector<int>ans(n);
        ans[n-1]=0;
        for(int i=n-2; i>=0; i--){
            if(nums[i]%2!=0){
                //odd
                ans[i]=preEven[i];
            }else ans[i]=preOdd[i];
        }
        return ans;
    }
};