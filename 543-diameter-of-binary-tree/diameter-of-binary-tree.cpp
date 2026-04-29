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
// tc: 0(n2)

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
    
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
    
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
    
        return max({leftHeight + rightHeight, leftDiameter, rightDiameter});
    }
    int height(TreeNode*root){
        if(!root) return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right) +1;
    }
};