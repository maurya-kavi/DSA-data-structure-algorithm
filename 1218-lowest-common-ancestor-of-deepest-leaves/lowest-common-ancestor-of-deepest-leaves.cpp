/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BinaryLiftingLCA {
private:
    int n;
    int colMax;
    vector<vector<int>> ancestorTable;
    vector<int> depth;

    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        depth[u] = d;
        ancestorTable[u][0] = p; 

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj);
            }
        }
    }

public:
    BinaryLiftingLCA(int nodes, int root, const vector<vector<int>>& adj) {
        n = nodes;
        colMax = __lg(n) + 1; // Applied the hardware-level optimization
        ancestorTable.assign(n, vector<int>(colMax, -1));
        depth.assign(n, 0);

        dfs(root, -1, 0, adj);

        for (int j = 1; j < colMax; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestorTable[i][j - 1] != -1) {
                    ancestorTable[i][j] = ancestorTable[ancestorTable[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];
        for (int j = 0; j < colMax; j++) {
            if ((diff >> j) & 1) { 
                u = ancestorTable[u][j];
            }
        }

        if (u == v) return u;

        for (int j = colMax - 1; j >= 0; j--) {
            if (ancestorTable[u][j] != -1 && ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }
};

class Solution {
private:
    int n = 0;
    unordered_map<TreeNode*, int> ptrToId;
    unordered_map<int, TreeNode*> idToPtr;
    vector<vector<int>> adj;
    vector<int> deepestNodes;
    int maxDepth = -1;

    // Assign a unique integer ID to every TreeNode
    void mapNodes(TreeNode* node) {
        if (!node) return;
        ptrToId[node] = n;
        idToPtr[n] = node;
        n++;
        mapNodes(node->left);
        mapNodes(node->right);
    }

    //  Build the adjacency list and collect the deepest leaves
    void buildGraph(TreeNode* node, int d) {
        if (!node) return;
        int u = ptrToId[node];

        if (d > maxDepth) {
            maxDepth = d;
            deepestNodes = {u}; // Found a new depth, reset the list
        } else if (d == maxDepth) {
            deepestNodes.push_back(u); // Add to current deepest leaves
        }

        if (node->left) {
            int v = ptrToId[node->left];
            adj[u].push_back(v);
            adj[v].push_back(u);
            buildGraph(node->left, d + 1);
        }
        if (node->right) {
            int v = ptrToId[node->right];
            adj[u].push_back(v);
            adj[v].push_back(u);
            buildGraph(node->right, d + 1);
        }
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;

        // Map the tree and prepare dimensions
        mapNodes(root);
        adj.assign(n, vector<int>());
        buildGraph(root, 0);

        //  Deploy your untouched template. ID 0 is always the root.
        BinaryLiftingLCA lca(n, 0, adj);

        //  Fold all deepest leaves into a single ancestor
        int commonAncestorId = deepestNodes[0];
        for (int i = 1; i < deepestNodes.size(); i++) {
            commonAncestorId = lca.getLCA(commonAncestorId, deepestNodes[i]);
        }

        // Translate the final ID back to the LeetCode structure
        return idToPtr[commonAncestorId];
    }
};