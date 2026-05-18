/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //  same as BT
        if(root==NULL || root==p || root==q) return root;
        // TreeNode*left=lowestCommonAncestor(root->left, p,q);
        // TreeNode*right=lowestCommonAncestor(root->right, p,q);

        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p,q);
        }else if(p->val > root->val && q->val >root->val){
            return lowestCommonAncestor(root->right, p,q);
        }else{
            return root;
        }

        // if(left && right) return root;
        // else if(left) return left;
        // else if(right) return right;
        // else return NULL;
    }
};