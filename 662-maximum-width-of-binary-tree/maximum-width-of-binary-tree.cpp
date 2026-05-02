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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        int maxWidth=0;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            // subtracting just to keep the number managable or prevent overflow of integer
            
            int levelMinInd=q.front().second;
            int first=0,last=0;
            for(int i=0; i<sz; i++){
                long long currInd=q.front().second-levelMinInd;
                TreeNode*node=q.front().first;
                if(i==0) first=currInd;
                if(i==sz-1) last=currInd;

                if(node->left) q.push({node->left, 2*currInd+1});
                if(node->right) q.push({node->right, 2*currInd+2});

                q.pop();
            }
            int currWidth=last-first+1;
            maxWidth=max(maxWidth, currWidth);

            
        }
        return maxWidth;
    }
};