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
    vector<int> preorder(Node* root) {
        vector<int>a;
        pre(root,a);
        return a;
    }

    void pre(Node*root, vector<int>&a){
        if(!root) return;

        a.push_back(root->val);
        vector<Node*>v=root->children;
        for(int i=0; i<v.size(); i++){
            pre(v[i],a);
        }
    }
};