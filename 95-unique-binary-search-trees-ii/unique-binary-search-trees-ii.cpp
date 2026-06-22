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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)  return {};
        return solve(1,n);
    }

    vector<TreeNode*>solve(int s, int e){
        vector<TreeNode*>res;

        if(s>e) {
            res.push_back(NULL);
            return res;
        }

        if(s==e){
            TreeNode*root=new TreeNode(s);
            res.push_back(root);
            return res;
        }

        for(int i=s; i<=e; i++){
            vector<TreeNode*>leftTree=solve(s,i-1);
            vector<TreeNode*>rightTree=solve(i+1,e);

            for(auto left:leftTree){
                for(auto right:rightTree){
                    TreeNode*root=new TreeNode(i);

                    root->left=left;
                    root->right=right;

                    res.push_back(root);
                }
            }
        }

        return res;
    }
};







