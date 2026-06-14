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
unordered_map<TreeNode*,int>mp;
int mxd=0;
    void depth(TreeNode*root, int d){
        if(!root) return;
        mxd=max(mxd,d);
        mp[root]=d;
        depth(root->left,d+1);
        depth(root->right,d+1);
    }
    TreeNode* lca(TreeNode*root){
        if(!root) return NULL;
        if(mp[root]==mxd){
            return root;
        }
        TreeNode*left=lca(root->left);
        TreeNode*right=lca(root->right);

        if(left && right) return root;
        return left?left:right; // if left then return the left , else if right is then return the right , if left is null and right is also null then return the right which is null too.
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root,0);
        return lca(root);
    }
};