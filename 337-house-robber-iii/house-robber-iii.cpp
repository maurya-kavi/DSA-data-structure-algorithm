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

unordered_map<TreeNode*, vector<int>> dp;

void init(TreeNode* root){
    if(!root) return;
    dp[root] = {-1, -1};
    init(root->left);
    init(root->right);
}

    int rob(TreeNode* root) {
        init(root);
        return solve(root,0);
    }

    int solve(TreeNode*root, int flag){

        if(!root) return 0;

        if (dp.count(root) && dp[root][flag] != -1)
        return dp[root][flag];

        int ans;

        // root le lo
        if(flag==0){
            int r=root->val;
            int left=0;
            if(root->left) left=solve(root->left, 1);
            int right=0;
            if(root->right) right=solve(root->right, 1);

            // if not taking root
            int from_left=0;
            if(root->left) from_left=solve(root->left,0);
            int from_right=0;
            if(root->right) from_right=solve(root->right,0);

            ans= max(r+left+right, from_left+from_right);
        }
        else{
            // cannot take the root due to flag =1
            int from_left=0;
            if(root->left) from_left=solve(root->left,0);
            int from_right=0;
            if(root->right) from_right=solve(root->right,0);

            ans= (from_left+from_right);
        }

        return dp[root][flag] = ans;
    }

};