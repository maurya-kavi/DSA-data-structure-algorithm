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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(root);
        while(!q1.empty()){
            int size=q1.size();
            vector<int>arr;
            for(int i=0;i<size;i++){
                TreeNode*curr=q1.front();
                arr.push_back(curr->val);
                if(curr->right) q2.push(curr->right);
                if(curr->left) q2.push(curr->left);
                q1.pop();
            }
            reverse(arr.begin(), arr.end());
            if(size>0) ans.push_back(arr);
            int size2=q2.size();
            // if(size==0) return ans;
            vector<int>brr;
            for(int i=0;i<size2;i++){
                TreeNode*curr=q2.front();
                brr.push_back(curr->val);
                if(curr->right) q1.push(curr->right);
                if(curr->left) q1.push(curr->left);
                q2.pop();
            }
            if(size2>0) ans.push_back(brr);
            
        }
        return ans;
    }
};