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
    int find(vector<int>&inorder, int start, int end,int target){
        for(int i=start; i<=end; i++){
            if(inorder[i]==target) return i;
        }
        return -1;
    }
    TreeNode*tree(vector<int>&in, vector<int>&post, int instart, int inend, int index){
        //index of postorder from the right side of array
        if(instart>inend) return nullptr;
        TreeNode*root=new TreeNode(post[index]);
        int pos=find(in,instart,inend, post[index]);

        root->right=tree(in,post,pos+1, inend, index-1);
        root->left=tree(in,post,instart, pos-1,index-inend+pos-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return tree(inorder,postorder,0,inorder.size()-1 , postorder.size()-1);
    }
};