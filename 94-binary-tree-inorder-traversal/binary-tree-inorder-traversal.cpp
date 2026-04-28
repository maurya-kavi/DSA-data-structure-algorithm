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
// void dfs(TreeNode*root, vector<int>&ans){
//     if(root==nullptr){
//         return;
//     }

//     dfs(root->left,ans);
//     ans.push_back(root->val);
//     dfs(root->right,ans);
// }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        unordered_map<TreeNode*,bool>mp;
        stack<TreeNode*>s;
        // if(root->right) s.push(root->right);
        if(root) s.push(root);
        // if(root->left) s.push(root->left);
        while(!s.empty()){
            TreeNode*node=s.top();
            s.pop();
            if(mp[node]==true) {
                ans.push_back(node->val);
                continue;
            }
            if(node->right) s.push(node->right);
            s.push(node);
            if(node->left) s.push(node->left);
            mp[node]=true;
        }
        return ans;
    }
};