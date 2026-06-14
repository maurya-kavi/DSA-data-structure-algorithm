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
// second approach
pair<int,TreeNode*> solve(TreeNode*root){
        if(!root) return {0,NULL};

        pair<int,TreeNode*>left=solve(root->left);
        pair<int,TreeNode*>right=solve(root->right);

        if(left.second && right.second) {
            if(left.first==right.first) return {left.first+1,root};
            else if(left.first>right.first){
                return {left.first+1,left.second};
            }else{
                return {right.first+1,right.second};
            }
        }
        else if(left.second){
            return {left.first+1,left.second};
        }
        else if(right.second){
            return {right.first+1,right.second};
        }
        else return {left.first+1,root};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};