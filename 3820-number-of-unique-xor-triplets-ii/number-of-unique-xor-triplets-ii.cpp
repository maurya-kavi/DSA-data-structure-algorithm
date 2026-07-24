class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int x=nums[i]^nums[j];
                s.insert(x);
            }
        }

unordered_set<int>st;
        for(int val:s){
            for(int i=0; i<n; i++){
                int x=val^nums[i];
                st.insert(x);
            }
        }

        return st.size();
    }
};