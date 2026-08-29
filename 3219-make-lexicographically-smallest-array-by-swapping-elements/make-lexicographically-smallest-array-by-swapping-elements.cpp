#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Pair elements with their original indices
        vector<pair<int, int>> val_idx(n);
        for (int i = 0; i < n; ++i) {
            val_idx[i] = {nums[i], i};
        }
        
        // Sort by value to easily find groups
        sort(val_idx.begin(), val_idx.end());
        
        vector<int> ans(n);
        int i = 0;
        
        // Grouping logic
        while (i < n) {
            int j = i + 1;
            // Expand the current group as long as the difference is <= limit
            while (j < n && val_idx[j].first - val_idx[j - 1].first <= limit) {
                j++;
            }
            
            // Extract and sort the original indices of this specific group
            vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(val_idx[k].second);
            }
            sort(indices.begin(), indices.end());
            
            // Assign the sorted values to the sorted indices
            for (int k = 0; k < indices.size(); ++k) {
                ans[indices[k]] = val_idx[i + k].first;
            }
            
            // Move to the start of the next group
            i = j; 
        }
        
        return ans;
    }
};