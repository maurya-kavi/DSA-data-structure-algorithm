class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string t="";
                t+=nums[i];
                t+=nums[j];
                if(t==target) cnt++;
                string p="";
                p+=nums[j];
                p+=nums[i];
                if(p==target) cnt++;
            }
        }
        return cnt;
    }
};