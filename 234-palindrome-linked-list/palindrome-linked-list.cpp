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
    bool isPalindrome(ListNode* head) {
        ListNode*curr=head;
        ListNode*h=head;
        ListNode*prev=nullptr;
        while(curr){
            ListNode*newNode=new ListNode(curr->val);
            curr=curr->next;
            newNode->next=prev;
            prev=newNode;
        }

        while(h && prev){
            if(h->val != prev->val) return false;
            h=h->next;
            prev=prev->next;
        }
        return true;
    }
};