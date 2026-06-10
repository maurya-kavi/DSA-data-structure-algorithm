/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*>s;
        ListNode*curr=head;
        bool found=false;
        while(!found && curr){
            if(s.count(curr)){
                found=true;
                return curr;
            }
            s.insert(curr);
            curr=curr->next;
        }
        return nullptr;
    }
};