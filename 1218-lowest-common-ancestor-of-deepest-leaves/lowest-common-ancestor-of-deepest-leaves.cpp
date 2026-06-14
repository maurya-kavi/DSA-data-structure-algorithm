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
    void depth(TreeNode*root, int d){
        if(!root) return;
        mp[root]=d;
        depth(root->left,d+1);
        depth(root->right,d+1);
    }
    TreeNode* lca(TreeNode*root, int &mxd){
        if(!root) return NULL;
        if(mp[root]==mxd){
            return root;
        }
        TreeNode*left=lca(root->left,mxd);
        TreeNode*right=lca(root->right,mxd);

        if(left && right) return root;
        else if(left) return left;
        else if(right) return right;
        else return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);
        int mxd=0;
        for(auto [key,val]:mp) mxd=max(mxd,val);
        // then use the same logic of lca
        return lca(root,mxd);

    }
};







