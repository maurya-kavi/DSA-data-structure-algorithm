class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // find the smallest odd element in the num1 if there is odd element in num1
        int cnte=0, cnto=0;
        int mnodd=INT_MAX, mneven=INT_MAX;

        for(int num:nums1) {
            if(num&1) { cnto++; mnodd=min(mnodd, num); }
            else { cnte++; mneven=min(mneven, num);}
        }

int n=nums1.size();
        if(cnto==0 || cnte==0) return true;

        // odd element is present
        if(mneven-mnodd >=1) return true;

        return false;
    }
};