class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        auto p=minmax_element(nums.begin(), nums.end());
        int mn=*p.first;
        int mx=*p.second;

        unordered_set<int>s;
        for(auto num:nums) s.insert(num);
vector<int>ans;
        for(int i=mn+1; i<mx; i++){
            if(!s.count(i)) ans.push_back(i);
        }

        return ans;
    }
};