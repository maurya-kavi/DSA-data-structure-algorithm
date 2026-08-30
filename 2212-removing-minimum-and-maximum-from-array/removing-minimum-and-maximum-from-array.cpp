class Solution {

public:

#define hahaha 0

    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int it1=min_element(nums.begin(), nums.end())-nums.begin();
        int it2=max_element(nums.begin(), nums.end())-nums.begin();

        if(it1==it2){
            return min(it1+1, n-it1);
        }

        if(it1>it2){
            return min({it2+1+n-it1, it1+1, n-it2});
        }

        if(it2>it1){
            return min({it1+1+n-it2, it2+1, n-it1});
        }

        return hahaha;
    }
};