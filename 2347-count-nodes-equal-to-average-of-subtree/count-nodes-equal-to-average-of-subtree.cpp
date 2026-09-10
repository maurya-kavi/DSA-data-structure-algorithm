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
int cnt=0;
pair<int,int> rec(TreeNode*root){
    if(!root){
        return {0,0}; // no of node , sum of nodes
    }
auto left=rec(root->left);
auto right=rec(root->right);

    int nodescnt=1+left.first + right.first;
    int sum=root->val + left.second + right.second;

    if(sum/nodescnt==root->val) cnt++;

    return {nodescnt,sum};
}

    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        pair<int,int>p=rec(root);

        return cnt;

    }
};