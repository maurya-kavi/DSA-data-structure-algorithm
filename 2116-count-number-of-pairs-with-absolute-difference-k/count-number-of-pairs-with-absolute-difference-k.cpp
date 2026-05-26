class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        for(int i=0; i<(n-1); i++){
            int l=i+1, r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(nums[mid]-nums[i] == k) {
                    int x=mp[nums[mid]];
                    cnt+=x;
                    break;
                }
                else if(nums[mid]-nums[i] > k) r=mid-1;
                else l=mid+1;
            }
        }
        return cnt;
    }
};