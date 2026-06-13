class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> result = {1}; // Base case: the beautiful array for n = 1
        
        while (result.size() < n) {
            vector<int> next_level;
            
            // Construct the Odd half (Left side)
            for (int x : result) {
                if (2 * x - 1 <= n) {
                    next_level.push_back(2 * x - 1);
                }
            }
            
            // Construct the Even half (Right side)
            for (int x : result) {
                if (2 * x <= n) {
                    next_level.push_back(2 * x);
                }
            }
            
            // Move up the recursive tree
            result = next_level;
        }
        
        return result;
    }
};