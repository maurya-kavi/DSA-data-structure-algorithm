class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
        // sort(nums.begin(), nums.end());
        for(int i=0; i<(int)nums.size(); i++){
            if(nums[i]%k==0) s.insert(nums[i]);
        }

        int need=k;
        while(true){
            if(!s.count(need)) return need;
            else need+=k;
        }

        return -1;
    }
};