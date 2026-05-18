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
    void solve(TreeNode*root, TreeNode*parent, int key){
        if(!root) return;
        if(root->val == key){
            if(root->left && root->right){
                if(parent->val < root->val) parent->right=root->left;
                else parent->left=root->left;
                TreeNode*curr=root->left;
                while(curr->right){
                    curr=curr->right;
                }
                curr->right=root->right;
                delete root;
                return;
            }else if(root->left){
                if(root->val >parent->val) parent->right=root->left;
                else parent->left=root->left;
                delete root;
                return;
            }else if(root->right){
                if(root->val > parent->val) parent->right=root->right;
                else parent->left=root->right;
                delete root;
                return;
            }
            else{
                // no leaf node
                if(parent->val < root->val) parent->right=NULL;
                else parent->left=NULL;
                delete root;

                return;
            }
        }
        if(key>root->val){
            solve(root->right, root,key);
        }
        else solve(root->left, root, key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode*node=root;
        if(root->val==key){
            if(root->left && root->right){
                TreeNode*newRoot=root->left;
                TreeNode*newRight=root->right;
                TreeNode*curr=newRoot;
                while(curr->right){
                    curr=curr->right;
                }
                curr->right=newRight;
                delete root;
                return newRoot;
            }else if(root->left){
                // parent->left=root->left;
                // delete root;
                return root->left;
            }else if(root->right){
                // parent->right=root->right;
                // delete root;
                return root->right;
            }else{
                delete root;
                return NULL;
            }
        }
        solve(node, NULL, key);
        if(!root) return NULL;
        return root;
    }
};