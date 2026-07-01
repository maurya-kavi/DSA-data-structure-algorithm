/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(!root) return res;

        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            for(int i=0; i<sz; i++){
            Node*node=q.front();
            temp.push_back(node->val);
            q.pop();
            vector<Node*>children=node->children;
            for(int i=0; i<children.size(); i++){
                q.push(children[i]);
            }
            }

            res.push_back(temp);
        }

        return res;
    }
};