class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a,b;
        int n=nums.size();
        a.push_back(nums[0]);
        b.push_back(nums[1]);

        for(int i=2; i<n; i++){
            if(a.back()>b.back()) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }

        vector<int>res=a;
        for(int i=0; i<b.size(); i++) res.push_back(b[i]);

        return res;
        
    }
};