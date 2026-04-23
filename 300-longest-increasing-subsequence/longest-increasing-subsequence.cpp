class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // here we will do in 0(nlogn) TC , using the Binary search algo
        int n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);

        for(int i=1; i<n; i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(temp.begin(), temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();

        // Intution:
        // instead of buiding all the incresing subsequence,
        // just update the value in the temp array 
        // temp will not give us the LIS values but their size will give the LIS.
    }
};