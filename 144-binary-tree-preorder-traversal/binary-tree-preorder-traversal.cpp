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
    
    vector<int>preorderTraversal(TreeNode*root){
        vector<int>pre;
        TreeNode*cur=root;
        while(cur){
            if(cur->left==NULL){
                pre.push_back(cur->val);
                cur=cur->right;
            }else{
                
                TreeNode*prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                
                if(prev->right==NULL){
                    // make a thread connection
                    pre.push_back(cur->val);
                    
                    prev->right=cur;
                    
                    cur=cur->left;
                }else{
                    // mtlb pahle se bana huaa tha toh connection hata do
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        
        return pre;
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
//     vector<int>pre=sol.preorderTraversal(root);
    
//     cout<<"hello"<<endl;
    
//     for(int i=0; i<pre.size(); i++){
//         cout<<pre[i]<<(i==pre.size()-1 ? "": " ");
//     }
//     cout<<endl;
    
//     return 0;
// }










