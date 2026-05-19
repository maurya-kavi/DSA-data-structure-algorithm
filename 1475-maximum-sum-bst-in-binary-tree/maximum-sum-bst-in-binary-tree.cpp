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

    int mxSum = 0;

    struct NodeInfo {
        bool isBST;
        int sum;
        int mini;
        int maxi;
    };

    NodeInfo solve(TreeNode* root) {

        // empty tree
        if(!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        // check BST property
        if(left.isBST &&
           right.isBST &&
           root->val > left.maxi &&
           root->val < right.mini) {

            int currSum =
                left.sum + right.sum + root->val;

            mxSum = max(mxSum, currSum);

            return {
                true,
                currSum,
                min(root->val, left.mini),
                max(root->val, right.maxi)
            };
        }

        // not BST
        return {false, 0, INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {

        solve(root);

        return mxSum;
    }
};