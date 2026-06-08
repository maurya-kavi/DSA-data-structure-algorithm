class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        int cnt=0;
        mp[0]=1;

        for(int i=0; i<n; i++){
            sum+=nums[i];
            int rem=sum-k; // look for the rem in the left side 
            if(mp.find(rem)!=mp.end()){
                cnt+=mp[rem];
            }
            mp[sum]++;
        }
        return cnt;
    }
};