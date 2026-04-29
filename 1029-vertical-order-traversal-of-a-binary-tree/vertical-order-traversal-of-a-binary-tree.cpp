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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp; // col,row,multiset
        // first map->col will be in the sorteed order
        // second map-> inside col, rows will be in the sorted order so top to bottom
        // multiset has been used so we can have same value or different values in the sorted order for the same row and col for multiple nodes

        queue<tuple<TreeNode*,int,int>>q; // treenode,row,col
        q.push({root,0,0});
        while(!q.empty()){
            auto [node,row,col]=q.front();
            q.pop();
            mp[col][row].insert(node->val);
            if(node->left) q.push({node->left,row+1,col-1});
            if(node->right) q.push({node->right,row+1,col+1});

        }

        vector<vector<int>>result;
        for(auto &p:mp){
            //p.first = col
            //p.second = map<int,multiset<int>>
            vector<int>colNodes; 
            // colNodes mein map<int,multiset<int>> ye saare element daal do
            for(auto &q:p.second){
                //q.first = row
                //q.second= multiset<int>
                colNodes.insert(colNodes.end(), q.second.begin(), q.second.end());
            }
            result.push_back(colNodes);
        }
        return result;
    }
};