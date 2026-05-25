class Solution {
public:
// we can replace the sorting by unsing innner map
    int winningPlayerCount(int n, vector<vector<int>>& pick) {

        unordered_map<int, unordered_map<int,int>> freq;

        int ans = 0;

        // Store frequencies
        for(auto &p : pick) {

            int player = p[0];
            int ball = p[1];

            freq[player][ball]++;
        }

        // Check winning condition
        for(auto &[player, mp] : freq) {

            for(auto &[ball, cnt] : mp) {

                if(cnt > player) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};