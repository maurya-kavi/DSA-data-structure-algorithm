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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};

        unordered_map<TreeNode*,TreeNode*>mp;
        mp[root]=NULL;

        vector<TreeNode*>a;

        queue<pair<TreeNode*,int>>q;
        q.push({root,targetSum});
        while(!q.empty()){
            TreeNode*node=q.front().first;
            int target=q.front().second;
            q.pop();
            target-=node->val;

            if(target==0 && node->left==NULL && node->right==NULL){
                a.push_back(node);
                continue;
            }

            // if(target<0) continue;

            if(node->left){
                mp[node->left]=node;
                q.push({node->left,target});
            }

            if(node->right){
                mp[node->right]=node;
                q.push({node->right,target});
            }
        }

        vector<vector<int>>res;

        for(int i=0; i<a.size(); i++){
            TreeNode* node=a[i];
            vector<int>b;
            b.push_back(node->val);
            while(mp[node]!=NULL){
                TreeNode* pNode=mp[node];
                b.push_back(pNode->val);
                node=pNode;
            }
            reverse(b.begin(),b.end());
            res.push_back(b);
        }

        return res;
    }
};