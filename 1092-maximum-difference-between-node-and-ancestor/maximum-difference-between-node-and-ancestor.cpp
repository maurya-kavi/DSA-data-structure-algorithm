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
int maxDiff=0;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return maxDiff;
    }
private:
    pair<int,int>dfs(TreeNode*root){
        if(!root) return {INT_MAX,INT_MIN}; // {min,max}

        pair<int,int>left=dfs(root->left);
        pair<int,int>right=dfs(root->right);

        int childMin=min(left.first,right.first);
        int childMax=max(left.second,right.second);

        if(childMin!=INT_MAX){
            maxDiff=max({maxDiff,abs(root->val-childMin), abs(root->val-childMax)});
        }

        return {min(root->val,childMin), max(root->val,childMax)};
    }
};