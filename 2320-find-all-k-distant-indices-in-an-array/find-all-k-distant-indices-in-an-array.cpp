class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        // if(n<=1) return {};
        vector<int>ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // if(abs(i-j)>k) break;
                if(i==j) continue;
                if(abs(i-j)<=k && nums[j]==key){
                    ans.push_back(i);
                }
                // if(abs(i-j)<=k && nums[i]==key){
                //     ans.push_back(j);
                // }
            }
        }
        for(int i=0; i<n; i++) {
            if(nums[i]==key) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()), ans.end());
        return ans;
    }
};