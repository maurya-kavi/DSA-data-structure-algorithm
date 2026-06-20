class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // left to right
        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        }

        // right to left
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        }

        int max_height = 0;

        for (int i = 1; i < m; i++) {
            int h1 = restrictions[i - 1][1];
            int h2 = restrictions[i][1];
            int d = restrictions[i][0] - restrictions[i - 1][0];
            
            max_height = max(max_height, (h1 + h2 + d) / 2);
        }

        max_height = max(max_height, restrictions.back()[1] + (n - restrictions.back()[0]));

        return max_height;
    }
};