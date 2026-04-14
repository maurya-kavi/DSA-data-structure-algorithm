class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
         int cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1; // means if we got the ssubarray with the odd number equal to k then what extra odd number required 0 , means it can be one of the valid subarray
        int cntt=0; //universal count
        for(int i=0; i<n; i++){
            if(nums[i] & 1) cntt++;
            
            if(mp.find(cntt-k)!=mp.end()) {
                cnt+=mp[cntt-k];
            }
            mp[cntt]++;
        }
        return cnt;
    }
};