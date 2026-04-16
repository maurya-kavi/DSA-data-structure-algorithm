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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode*curr=head;
        int n=0;
        while(curr!=nullptr){
            n++;
            curr=curr->next;
        }
        if(k%n==0) return head;
        int k1=k%n;
        int n1=n-k1;
        //n1 ke baad wale node ko head ke aage connect kar do
        curr=head;
        ListNode*prev=new ListNode();
        while(n1!=0){
            prev=curr;
            curr=curr->next;
            n1--;
        }
        prev->next=nullptr;
        ListNode*breakN=curr;
        while(breakN && breakN->next!=nullptr){
            breakN=breakN->next;
        }
        // if(breakN) 
        breakN->next=head;
        
        
        return curr;
    }
};