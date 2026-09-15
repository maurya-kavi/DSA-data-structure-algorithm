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


#include<bits/stdc++.h>
using namespace std;

// struct TreeNode {
//   int val;
//   TreeNode*left;
//   TreeNode*right;
//   TreeNode(int x){
//       val=x;
//       left=nullptr;
//       right=nullptr;
//   }
// };


class Solution {
    public:
    
    vector<int>inorderTraversal(TreeNode*root){
        vector<int>inorder;
        TreeNode*cur=root;
        while(cur){
            if(cur->left==NULL){
                inorder.push_back(cur->val);
                cur=cur->right;
            }else{
                
                TreeNode*prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                
                if(prev->right==NULL){
                    // make a thread connection
                    prev->right=cur;
                    // and move to the left node of cur, so agar uska bhi left mein koi node hoga toh uss left node ka rightmost node iss se connection banayega
                    
                    cur=cur->left;
                }else{
                    // mtlb pahle se bana huaa tha toh connection hata do
                    prev->right=nullptr;
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        
        return inorder;
    }
};

// int main(){
//     TreeNode*root=new TreeNode(1);
//     root->left=new TreeNode(2);
//     root->right=new TreeNode(3);
//     root->left->left=new TreeNode(4);
//     root->left->right=new TreeNode(5);
//     root->left->right->right= new TreeNode(6);
    
//     Solution sol;
//     vector<int>inorder=sol.inorderTraversal(root);
    
//     cout<<"hello"<<endl;
    
//     for(int i=0; i<inorder.size(); i++){
//         cout<<inorder[i]<<(i==inorder.size()-1 ? "": " ");
//     }
//     cout<<endl;
    
//     return 0;
// }









