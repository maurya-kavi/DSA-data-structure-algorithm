class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        vector<int>rem_freq(k,0); // store the freq of rem for 0 to (n-1)
        rem_freq[0]=1;
        int running_sum=0;
        
        for(int i=0; i<n; i++){
            running_sum+=nums[i];
            int rem=(k+(running_sum%k))%k;
            cnt+=rem_freq[rem];
            rem_freq[rem]++;
        }
        return cnt;
    }
};