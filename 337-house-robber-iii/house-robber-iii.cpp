class Solution {
public:
    std::pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        
        int take = root->val + l.second + r.second;
        int not_take = std::max(l.first, l.second) + std::max(r.first, r.second);
        
        return {take, not_take};
    }
    
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return std::max(res.first, res.second);
    }
};