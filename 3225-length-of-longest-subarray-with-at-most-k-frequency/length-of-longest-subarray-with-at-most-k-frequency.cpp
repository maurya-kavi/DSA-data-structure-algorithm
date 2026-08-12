class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
         // sliding window
        int ans=0;
        int n=nums.size();
        int cnt=0;
        int j=0;
        for(int i=0; i<n; i++){
            if(!mp.count(nums[i]) || mp[nums[i]]<k){
                mp[nums[i]]++;
                cnt++;
                ans=max(ans,cnt);
            }else{
                bool flag=false;
                while(!flag && j<i){
                    if(nums[j]!=nums[i]) {
                        mp[nums[j]]--;
                        j++;
                    }
                    else{
                        int ind=j;
                        int len=i-j;
                        cnt=len;
                        ans=max(ans,len);
                        j++;
                        flag=true;
                    }
                }
            }
        }
        return ans;
    }
};