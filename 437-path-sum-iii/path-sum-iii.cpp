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
using ll=long long;
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;

        unordered_map<ll,ll>mp;
        mp[0]=1;

        return solve(root,0, targetSum, mp);
        
    }

    int solve(TreeNode*root, ll runningSum, ll targetSum, unordered_map<ll,ll>&mp){
        if(!root) return 0;

        runningSum+=root->val;
        ll cnt=mp[runningSum-targetSum];
        // if(mp.count(runningSum-targetSum) && mp[runningSum-targetSum]==1) cnt+=mp[runningSum-targetSum];
        mp[runningSum]++;

        cnt+=solve(root->left, runningSum, targetSum,mp);
        cnt+=solve(root->right, runningSum, targetSum,mp);

        mp[runningSum]--;

        return cnt;
    }
};

/* -----recursive solution (two function approach)
TC: n*(n+1)/2 = approx (n^2);
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;

        return pathSum(root->left,targetSum) + pathSum(root->right, targetSum) + f(root,targetSum);
    }

    int f(TreeNode*root, long long targetSum){
        if(root==NULL) return 0;
        int cnt=0;
        if(targetSum==root->val) cnt=1;
        long long newSum=1LL*targetSum-1LL*root->val;
        cnt+=f(root->left,newSum);
        cnt+=f(root->right,newSum);

        return cnt;

    }
};
*/