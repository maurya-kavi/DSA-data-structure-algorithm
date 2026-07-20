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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*newNode=new TreeNode(val);
            newNode->left=root;
            newNode->right=nullptr;
            return newNode;
        }
depth--;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            // treeNode*node=q.front();
            
            if(depth==1){
                int sz=q.size();
                for(int i=0; i<sz; i++){
                    TreeNode*node=q.front();
                    q.pop();
                    TreeNode*left=node->left;
                    TreeNode*right=node->right;

                    // TreeNode*newNode=new TreeNode(val);
                    node->left=new TreeNode(val);
                    node->right=new TreeNode(val);
                    node->left->left=left;
                    node->left->right=nullptr;
                    node->right->right=right;
                    node->right->left=nullptr;

                    
                }
                break;
            }

            int sz=q.size();
            for(int i=0; i<sz; i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            depth--;
        }
return root;
    }
};