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
// optimization 
    TreeNode*prev=NULL;
    TreeNode*first=NULL;
    TreeNode*second=NULL;

    void inorder(TreeNode*root){
        if(!root) return;
        inorder(root->left);
        if(prev && prev->val > root->val){
            if(first==NULL){
                first=prev;
            }
            second=root;
        }
        prev=root;
        inorder(root->right);
    }

    // given function
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(second->val, first->val);
    }

    // lets dry run the first example
    // inorder(root->left) when reach at node 3, noleft node so return then at that time prev was NULL , then prev=root and look in the right side so for node 2 no left node so return then prev is ow not NULL so first=prev(3) and second=root(2); then look in the right there is nothing so return from 2 to 3 then 3 to 1, now we are on the root node 1, so for node 1 its left part returned then look for the prev->val > root-> val yes then first is not null so it no tchange, second=change from 2 to 1(root);
    // swap the second and first node val 
};