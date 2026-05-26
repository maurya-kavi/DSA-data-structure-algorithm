class Solution {
public:
// lets optimize itttt
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        int cnt=0;
        unordered_map<string,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(auto&s:nums){
            //check if s is the prefix of the target
            if(target.find(s)==0){
                //if s is prefix of target is then is is true
                // now look for the rem is present in the map or not
                string rem=target.substr(s.size()); // giving the begining index to get rem fromthere to last char of string target
                cnt+=mp[rem];

                //if prefix == sufix then cnt--;  as  i!=j
                if(s==rem) cnt--;
            }
        }
        return cnt;
    }
};