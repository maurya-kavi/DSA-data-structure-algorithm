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
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node*>q;
        q.push(root);
int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            cnt++;
            for(int i=0; i<sz; i++){
                Node*node=q.front();
                q.pop();
                vector<Node*>ch=node->children;
                for(int j=0; j<ch.size(); j++){
                    q.push(ch[j]);
                }
            }

        }
        return cnt;
    }
};