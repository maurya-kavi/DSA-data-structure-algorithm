/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*, Node*> mp;

        queue<Node*>q;

        q.push(node);
        //cloned first node
        mp[node]=new Node(node->val);

        while(!q.empty()){
            Node*curr=q.front();
            q.pop();
            
            //check for neighbor cloned or not
            for(Node*neighbor:curr->neighbors){
                //if not cloned
                if(!mp.count(neighbor)){
                    q.push(neighbor);
                    mp[neighbor]=new Node(neighbor->val);
                }
                //add the cloned neighbor cloned to the curr node
            mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }
        return mp[node];
    }
};