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
    int findIndex(vector<int>&inorder , int target, int start, int end){
        for(int i=start; i<=end; i++){
            if(inorder[i]==target) return i;

        }
        return -1;
    }
    TreeNode* tree(vector<int>&in , vector<int>&pre, int instart , int inend , int index){
        if(instart>inend) return nullptr;
        TreeNode*root=new TreeNode(pre[index]);
        int pos=findIndex(in,pre[index],instart,inend);
        
        root->left=tree(in, pre, instart, pos-1, index+1);
        root->right=tree(in,pre,pos+1,inend,index+(pos-instart)+1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return tree(inorder,preorder , 0, inorder.size()-1,0);
    }
};