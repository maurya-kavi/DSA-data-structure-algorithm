class DSU {
public:
    vector<int>rank,parent,size;

    // construct to initialize dsu
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i]=i;
            size[i]=1;
        }
    }
    // fun to find ultimate parent with path compression
    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }

    // function to preform union by rank
    void unionByRank(int u, int v){
        int ulp_u=findUPar(u); // find the ultimate parent of u
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_u]=ulp_v;
            rank[ulp_u]++;
        }
    }

    // function to perform union by size
    void unionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
// let's approach it using disjointset --- dsu
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        // DSU needs n * n nodes to represent the entire grid
        DSU dsu(n * n);
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // PHASE 1: Connect all existing 1s to build the islands
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    
                    // Look at all 4 neighbors
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        
                        // If neighbor is valid and is also land, union them!
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int nodeNo = r * n + c;
                            int adjNodeNo = nr * n + nc;
                            dsu.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }

        // The Phantom Union (Sweep the 0s)
        int mx = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    
                    // Set to store UNIQUE ultimate parents around this 0
                    unordered_set<int> uniqueParents;
                    
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            uniqueParents.insert(dsu.findUPar(nr * n + nc));
                        }
                    }

                    // Calculate potential size: 1 (for the flipped 0) + sizes of adjacent islands
                    int totalSize = 1;
                    for (auto it : uniqueParents) {
                        totalSize += dsu.size[it];
                    }
                    
                    mx = max(mx, totalSize);
                }
            }
        }

        // EDGE CASE: What if there were NO zeros? (Grid is all 1s)
        for (int cell = 0; cell < n * n; cell++) {
            mx = max(mx, dsu.size[dsu.findUPar(cell)]);
        }

        return mx;
    }
};

