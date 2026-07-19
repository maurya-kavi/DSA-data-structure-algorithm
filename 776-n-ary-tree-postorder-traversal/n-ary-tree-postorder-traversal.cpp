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
    vector<int> postorder(Node* root) {
        vector<int>a;
        post(root,a);
        return a;

    }

    void post(Node*root, vector<int>&a){
        if(!root) return;

        vector<Node*>v=root->children;
        for(int i=0; i<v.size(); i++){
            post(v[i], a);
        }

        a.push_back(root->val);
    }
};