class Solution {
    struct State { int r, c, mask, e, moves; };
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        int start_r = -1, start_c = -1, l_idx = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') { start_r = i; start_c = j; }
                else if (classroom[i][j] == 'L') { litter_id[i][j] = l_idx++; }
            }
        }
        
        int target_mask = (1 << l_idx) - 1;
        // 3D Array: max_energy[r][c][mask]
        vector<vector<vector<int>>> max_energy(m, vector<vector<int>>(n, vector<int>(1 << l_idx, -1)));
        
        queue<State> q;
        q.push({start_r, start_c, 0, energy, 0});
        max_energy[start_r][start_c][0] = energy;
        
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            
            if (curr.mask == target_mask) return curr.moves;
            
            for (auto& d : dirs) {
                int nr = curr.r + d[0], nc = curr.c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int ne = curr.e - 1;
                    if (ne < 0) continue;
                    if (classroom[nr][nc] == 'R') ne = energy;
                    
                    int nmask = curr.mask;
                    if (litter_id[nr][nc] != -1) nmask |= (1 << litter_id[nr][nc]);
                    
                    // Core Pruning Logic: Only push if we arrive with strictly MORE energy
                    if (ne > max_energy[nr][nc][nmask]) {
                        max_energy[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne, curr.moves + 1});
                    }
                }
            }
        }
        return -1;
    }
};