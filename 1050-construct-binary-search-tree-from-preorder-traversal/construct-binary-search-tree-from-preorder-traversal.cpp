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
    TreeNode*solve(vector<int>&preorder,int &ind, int lower, int upper){
        if(ind==preorder.size() || preorder[ind]<lower || preorder[ind]>upper) return NULL;

        TreeNode*root=new TreeNode(preorder[ind++]);
        root->left=solve(preorder, ind, lower, root->val);
        root->right=solve(preorder, ind, root->val, upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        int lower=INT_MIN;
        int upper=INT_MAX;
        return solve(preorder,ind, lower, upper);
    }
};