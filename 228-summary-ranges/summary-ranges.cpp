class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n=nums.size();
        vector<string> ans;
        if(nums.empty()) return ans;
        string word=to_string(nums[0]);
        string prev="";
        for(int i=1; i<n; i++){
            if(1LL*nums[i]-1LL*nums[i-1]==1){
                prev=to_string(nums[i]);

            }else{
                if(prev!=""){
                word+="->" + prev;
                }
                
                ans.push_back(word);
                word=to_string(nums[i]);
                prev="";
            }
        }
        if(prev==""){
            ans.push_back(word);
        }else{
            ans.push_back(word+"->"+prev);
        }
        return ans;
    }
};