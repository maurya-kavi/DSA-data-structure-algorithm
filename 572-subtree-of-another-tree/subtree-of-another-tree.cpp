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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);
bool found=false;
// TreeNode*reqNode;
vector<TreeNode*>reqNode;

        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node->val==subRoot->val){
                // reqNode=node;
                reqNode.push_back(node);
                found =true;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        if(found==false) return false;

for(int i=0; i<reqNode.size(); i++){
        queue<TreeNode*>q1,q2;
        q1.push(reqNode[i]);
        q2.push(subRoot);

        while(!q1.empty() && !q2.empty() && q1.size()==q2.size()){
            if(q1.front()->val != q2.front()->val) break;

if(q1.front()->left && !q2.front()->left ) break;
if(!q1.front()->left && q2.front()->left ) break;
if(q1.front()->right && !q2.front()->right ) break;
if(!q1.front()->right && q2.front()->right ) break;       

            if(q1.front()->left) {
            if(q2.front()->left==nullptr) break;
            if(q1.front()->left->val != q2.front()->left->val) break;
            q1.push(q1.front()->left);
            q2.push(q2.front()->left);
            }

            if(q1.front()->right) {
            if(q2.front()->right==nullptr) break;
            if(q1.front()->right->val != q2.front()->right->val) break;
            q1.push(q1.front()->right);
            q2.push(q2.front()->right);
            }


             q1.pop();
            q2.pop();
        }

        if(q1.empty() && q2.empty()) return true;
}

        return false;
    }
};