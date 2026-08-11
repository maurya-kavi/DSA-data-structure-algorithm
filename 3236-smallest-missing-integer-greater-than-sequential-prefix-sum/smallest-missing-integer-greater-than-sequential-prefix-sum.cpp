class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        vector<int>seq;
        seq.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]+1) seq.push_back(nums[i]);
            else break;
        }

        int sum=accumulate(seq.begin(), seq.end(), 0LL);

        set<int>s;
        for(int num:nums) s.insert(num);

        int x=sum;
        while(true){
            if(!s.count(x)) return x;
            else x++;
        }
        return -1;
    }
};