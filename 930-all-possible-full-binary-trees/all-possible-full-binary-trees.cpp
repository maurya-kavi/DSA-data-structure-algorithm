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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        if(n==1) {
            TreeNode*root=new TreeNode(0);
            return {root};
        }
        return solve(1,n);
    }
    vector<TreeNode*>solve(int s, int e){
        vector<TreeNode*>res;
        if(s>e) {
            res.push_back(NULL);
            return res;
        }
        if(s==e){
            TreeNode*root=new TreeNode(0);
            res.push_back(root);
            return res;
        }

        for(int i=s+1; i<=e; i+=2){
            vector<TreeNode*>leftTree=solve(s,i-1);
            vector<TreeNode*>rightTree=solve(i+1,e);
            for(auto left:leftTree){
                for(auto right:rightTree){
                    TreeNode*root=new TreeNode(0);
                    root->left=left;
                    root->right=right;

                    res.push_back(root);
                }
            }
        }

        return res;
    }
};