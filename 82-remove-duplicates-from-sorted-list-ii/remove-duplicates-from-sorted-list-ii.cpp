/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*curr=head;
        ListNode*dummy=new ListNode();
        dummy->next=head;
        ListNode*prev=dummy;

        while(curr){
            if(curr->next && curr->val==curr->next->val){
                int depval=curr->val;
                while(curr && curr->val==depval){
                    curr=curr->next;
                }
                prev->next=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};