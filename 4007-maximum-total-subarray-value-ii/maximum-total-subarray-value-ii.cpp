#include <vector>
#include <algorithm>

using namespace std;

class SparseTable {
private:
    int n;
    int K;
    // max_st[i][j] stores the max in range [i, i + 2^j - 1]
    vector<vector<long long>> max_st;
    vector<vector<long long>> min_st;

public:
    // O(N log N) Build Time
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        // The maximum power of 2 needed to cover length 'n'
        K = std::__lg(n) + 1; 

        max_st.assign(n, vector<long long>(K));
        min_st.assign(n, vector<long long>(K));

        // Base case: intervals of length 2^0 = 1
        for (int i = 0; i < n; i++) {
            max_st[i][0] = arr[i];
            min_st[i][0] = arr[i];
        }

        // Build the table: Combine two intervals of length 2^(j-1)
        // to form an interval of length 2^j
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                
                // The left half: starts at i
                long long left_max = max_st[i][j - 1];
                long long left_min = min_st[i][j - 1];
                
                // The right half: starts at i + 2^(j-1)
                long long right_max = max_st[i + (1 << (j - 1))][j - 1];
                long long right_min = min_st[i + (1 << (j - 1))][j - 1];
                
                max_st[i][j] = max(left_max, right_max);
                min_st[i][j] = min(left_min, right_min);
            }
        }
    }

    // O(1) Query Time for the inclusive range [L, R]
    pair<long long, long long> query(int L, int R) {
        // Find the length of the range
        int len = R - L + 1;
        
        // Find the largest power of 2 that fits entirely inside 'len'
        int j = std::__lg(len); 
        
        // Overlap the block starting at L and the block ending at R
        long long max_val = max(max_st[L][j], max_st[R - (1 << j) + 1][j]);
        long long min_val = min(min_st[L][j], min_st[R - (1 << j) + 1][j]);

        return {min_val, max_val};
    }
};


class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        SparseTable st(nums);
        int n = nums.size();
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int l=0; l<n; l++){
            int r=n-1;
            pair<long long,long long>mxmn=st.query(l,r);
            int diff=mxmn.second-mxmn.first;
            pq.push({diff,{l,r}});
        }
        long long ans=0;
        while(k){
            auto [diff,lr]=pq.top();
            pq.pop();
            ans+=diff;
            auto [l,r]=lr;
            r--;
            if(l<=r){
                pair<long long,long long>mxmn=st.query(l,r);
                int diff=mxmn.second-mxmn.first;
                pq.push({diff,{l,r}});
            }
            k--;
        }
        return ans;
    }
};