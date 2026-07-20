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
    string tree2str(TreeNode* root) {
        string s="";
        preorder(root,s);
        return s;
    }

    void preorder(TreeNode*root,string &s){
if(!root) return;

        // s+=root->val+'0';
        if(root->val >=0 ) s += to_string(root->val);
        else {
            s+='-';
            int x=abs(root->val);
           s += to_string(x);
        }

        if(root->left || root->right){
        s+='(';
        preorder(root->left,s);
        s+=')';
        }
        if(root->right){
        s+='(';
        preorder(root->right,s);
        s+=')';
        }
    }
};












