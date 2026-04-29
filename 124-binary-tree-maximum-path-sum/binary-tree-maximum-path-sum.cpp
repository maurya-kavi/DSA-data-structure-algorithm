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
int maxSum=INT_MIN;
    int maxPathFromNode(TreeNode*root){
        if(!root) return 0;
        int left=max(0,maxPathFromNode(root->left));
        int right=max(0,maxPathFromNode(root->right));

        return root->val + max(left,right);
    }
    void dfs(TreeNode*root){
        if(!root) return;
        int left=max(0,maxPathFromNode(root->left));
        int right=max(0,maxPathFromNode(root->right));

        int current=left+right+root->val;
        maxSum=max(maxSum,current);

// and traverse for remaining node
        dfs(root->left);
        dfs(root->right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};