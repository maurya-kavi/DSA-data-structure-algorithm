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
bool found=true;
    bool isBalanced(TreeNode* root) {
        checkHeight(root);
        return found;

    }
    int checkHeight(TreeNode*root){
        if(!root) return 0;
        int right=checkHeight(root->right);
        int left=checkHeight(root->left);
        if(abs(left-right)>1) found=false;
        return max(left,right)+1;
    }
};