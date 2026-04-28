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
// void dfs(TreeNode*root,vector<int>&ans){
//     if(root==nullptr) return;
//     dfs(root->left,ans);
//     dfs(root->right,ans);
//     ans.push_back(root->val);
// }
    vector<int> postorderTraversal(TreeNode* root) {
        //post order LRN, we will build NRL then reverse it
        //using one stack 
        stack<TreeNode*>s;
        vector<int>ans;
        if(!root) return ans;
        s.push(root);
        while(!s.empty()){
            TreeNode*node=s.top();
            s.pop();
            ans.push_back(node->val);
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};