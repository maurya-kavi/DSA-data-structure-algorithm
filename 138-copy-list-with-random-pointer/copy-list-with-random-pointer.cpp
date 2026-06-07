/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*,Node*>mp;
        Node*curr=head;
        while(curr){
            mp[curr]=new Node(curr->val); // create all node and stroe the relation in the map
            curr=curr->next;
        }

        // now assign next and random
        curr=head;
        while(curr){
            mp[curr]->next=mp[curr->next];
            mp[curr]->random=mp[curr->random];

            curr=curr->next;
        }
        return mp[head];
    }
};