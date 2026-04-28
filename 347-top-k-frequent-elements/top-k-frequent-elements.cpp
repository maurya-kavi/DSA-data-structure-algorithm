class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int x:nums) mp[x]++;
        priority_queue<pair<int,int>>pq;
        for(auto [key,val]:mp){
            pq.push({val,key});
        }
        vector<int>ans;
        while(k--){
            auto [f,s] = pq.top();
            pq.pop();
            ans.push_back(s);
        }
        return ans;
    }
};