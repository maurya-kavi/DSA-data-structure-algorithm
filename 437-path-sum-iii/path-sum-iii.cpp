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
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;

        return pathSum(root->left,targetSum) + pathSum(root->right, targetSum) + f(root,targetSum);
    }

    int f(TreeNode*root, long long targetSum){
        if(root==NULL) return 0;
        int cnt=0;
        if(targetSum==root->val) cnt=1;
        long long newSum=1LL*targetSum-1LL*root->val;
        cnt+=f(root->left,newSum);
        cnt+=f(root->right,newSum);

        return cnt;

    }
};