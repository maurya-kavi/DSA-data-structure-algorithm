class DSU {
    vector<int>rank,parent,size;
public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        
        DSU dsu(n);

        // Map to store email -> account index
        unordered_map<string, int> mapMailNode;

        // Union accounts having common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    dsu.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // Group emails under ultimate parent
        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = dsu.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        // Prepare final merged result
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        // Sort final answer
        sort(ans.begin(), ans.end());
        return ans;

    }
};