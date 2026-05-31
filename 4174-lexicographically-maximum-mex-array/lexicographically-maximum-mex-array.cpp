class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n=nums.size();
        vector<int>suf_mex(n);
        vector<bool>present(n+2,0);
        int curr_mex=0;
        for(int i=n-1; i>=0; i--){
            if(nums[i]<(n+2)){
                present[nums[i]]=true;
            }
            while(present[curr_mex]){
                curr_mex++;
            }
            suf_mex[i]=curr_mex;
        }

        // left to right greedy execution
        vector<int>result;
        int i=0;
        while(i<n){
            int target=suf_mex[i];
            result.push_back(target);

            if(target==0){
                i++;
                continue;
            }

            int needed=target;
            vector<bool>seen(target,false);
            int j=i;
            while(j<n && needed>0){
                if(nums[j]<target && !seen[nums[j]]){
                    seen[nums[j]]=true;
                    needed--;
                }
                j++;
            }
            i=j;
        }
        return result;
    }
};