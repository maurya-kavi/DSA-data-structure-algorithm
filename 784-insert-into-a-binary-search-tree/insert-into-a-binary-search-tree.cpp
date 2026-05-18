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
    void solve(TreeNode*root, TreeNode*parent, int &val){
        // given that val should  not be same as any val of the given tree
        
        if(val>root->val) {
            if(root->right) solve(root->right,root, val);
            else {
                TreeNode*newNode=new TreeNode(val);
                root->right=newNode;
                return;
            }
        }
        else{
            if(root->left) solve(root->left, root, val);
            else{
                TreeNode*newNode=new TreeNode(val);
                root->left=newNode;
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode*newNode=new TreeNode(val);
            return newNode;
        }
        TreeNode*node=root;
        solve(node, NULL, val);
        return root;
        // if(!root){
        //     TreeNode*newNode=new TreeNode(val);
        //     return newNode;
        // }
        // // if val is same or less than then mmove in the left , else right
        // if(root->val >= val){
        //     return insertIntoBST(root->left, val);
        // }else return insertIntoBST(root->right,val);
    }
};