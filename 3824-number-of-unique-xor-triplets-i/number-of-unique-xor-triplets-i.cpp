class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
// this is form the obeservation
int index=0;
        while(n>=2){
            index++;
            n/=2;
        }

        return pow(2,index+1);
    }
};