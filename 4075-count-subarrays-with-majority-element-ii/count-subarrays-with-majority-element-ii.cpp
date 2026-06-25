class Solution {
public:
#define ll long long
// using merge sort ---- this is similar like the inversion count problem

    //---- Helper function to perform merge sort and count valid pairs
    ll mergeSortAndCount(vector<ll>& P, ll left, ll right) {
        if (left >= right) return 0;
        
        ll mid = left + (right - left) / 2;
        
        ll count = mergeSortAndCount(P, left, mid) + mergeSortAndCount(P, mid + 1, right);
        
        ll i = left;
        ll j = mid + 1;
        while (i <= mid && j <= right) {
            if (P[i] < P[j]) {
                // If P[i] < P[j], then P[i] is also less than everything 
                // from P[j] to P[right] because the right half is sorted!
                count += (right - j + 1);
                i++;
            } else {
                j++; 
            }
        }
        
        vector<int> temp;
        i = left;
        j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (P[i] <= P[j]) {
                temp.push_back(P[i++]);
            } else {
                temp.push_back(P[j++]);
            }
        }
        
        while (i <= mid) temp.push_back(P[i++]);
        while (j <= right) temp.push_back(P[j++]);
        
        for (ll k = left; k <= right; k++) {
            P[k] = temp[k - left];
        }
        
        return count;
    }

    ll countMajoritySubarrays(vector<int>& nums, int target) {
        ll n = nums.size();
        
        vector<ll> P(n + 1, 0);
        for (ll i = 0; i < n; i++) {
            P[i + 1] = P[i] + (nums[i] == target ? 1 : -1);
        }
        
        return mergeSortAndCount(P, 0, n);
    }
};