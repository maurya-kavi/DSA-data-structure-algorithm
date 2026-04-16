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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*curr=head;
        int count=0;
        while(curr!=nullptr){
            count++;
            curr=curr->next;
        }
        int ns=count-n+1;
        if(ns==1){
            head=head->next;
        }
        curr=head;
        // ListNode*prev=new ListNode();
        ListNode*preprev=new ListNode();
        // ListNode*next=new ListNode();
        while(ns!=0){
            // preprev->next=prev;
            if(ns==2) preprev=curr;
            // prev=curr;
            if(curr!=nullptr) curr=curr->next;
            
            ns--;
        }
        preprev->next=curr;
        
        return head;
    }
};