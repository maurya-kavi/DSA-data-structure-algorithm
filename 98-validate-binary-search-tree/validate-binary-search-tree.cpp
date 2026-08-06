/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isValidBST(TreeNode* root) {
        return solve(root,nullptr,nullptr);
    }

    bool solve(TreeNode*root, TreeNode*mn, TreeNode* mx){
        if(!root) return true;

        if((mn && mn->val >= root->val) || (mx && mx->val<=root->val)) return false; 

        bool left=solve(root->left, mn, root);
        bool right=solve(root->right, root, mx);

        if(left && right) return true;

        return false;
    }
};