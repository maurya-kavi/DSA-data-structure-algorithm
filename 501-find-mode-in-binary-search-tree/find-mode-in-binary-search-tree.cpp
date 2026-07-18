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
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;

        unordered_map<int,int>mp;

        TreeNode*cur=root;
        queue<TreeNode*>q;
        q.push(root);
       
int mxfre=0;

        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            mp[node->val]++;

mxfre=max(mxfre,mp[node->val]);

            if(node->left) {
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }

        int sz=mp.size();

for(auto [key,val]:mp){
    if(val==mxfre) ans.push_back(key);
}

return ans;
    }
};