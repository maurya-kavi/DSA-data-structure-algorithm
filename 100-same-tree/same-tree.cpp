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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;
        if(p->val!=q->val) return false;
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        TreeNode*c1=p;
        TreeNode*c2=q;
        q1.push(c1);
        q2.push(c2);
        while(!q1.empty() && !q2.empty()){
            TreeNode*temp1=q1.front();
            TreeNode*temp2=q2.front();

            if(q1.front() && q2.front() && q1.front()->val!=q2.front()->val) return false;
            q1.pop();
            q2.pop();
            
            if((temp1->left && !temp2->left) || (temp2->left && !temp1->left)) return false;
            if((temp1->right && !temp2->right) || (temp2->right && !temp1->right)) return false;
            if(temp1->left) q1.push(temp1->left);
            if(temp1->right) q1.push(temp1->right);
            if(temp2->left) q2.push(temp2->left);
            if(temp2->right) q2.push(temp2->right);
        }
        if(!q1.empty() || !q2.empty()){
            return false;
        }
        return true;
    
    }
};