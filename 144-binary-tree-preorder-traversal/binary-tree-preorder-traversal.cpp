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
//     ans.push_back(root->val);
//     dfs(root->left, ans);
//     dfs(root->right,ans);
// }
    vector<int> preorderTraversal(TreeNode* root) {
        //iterative approach for the preorder traversal of the binary tree
        
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>s;
        if(root) s.push(root);
        
        // note: root is not moving , node is moving if you consider root then it will give you the mle
        while(!s.empty()){
            TreeNode*node=s.top();
            ans.push_back(s.top()->val);
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return ans;
    }
};