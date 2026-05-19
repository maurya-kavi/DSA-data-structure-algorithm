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
    void findsortarr(TreeNode*root, int k , vector<int>&a){
        if(!root) return;
        //LNR
        findsortarr(root->left, k,a);
        a.push_back(root->val);
        findsortarr(root->right, k, a);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>a;
        findsortarr(root,k,a);
        // now have the a as sorted array
        int n=a.size();
        if(n<2) return false;
        int sum=a[0]+a[n-1];
        if(sum==k) return true;
        int l=1, r=n-2;
        while(l<=r){
            if(sum<k){
                sum-=a[l-1];
                sum+=a[l];
                l++;
            }else if(sum>k){
                sum-=a[r+1];
                sum+=a[r];
                r--;
            }

            if(sum==k) return true;
        }
        return false;
    }
};