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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //assuming left or right in the bound of ll given
        //store left to right in a stack and delete it from ll
        //reverse it 
        //prev for just before left and next for just after right in ll
        //prev->reversed ll -> next

        stack<ListNode*>s;
        int count=1;
        ListNode*curr=head;
        ListNode*prev=new ListNode();
        ListNode*nextt=new ListNode();
        while(count<left){
            prev=curr;
            curr=curr->next;
            
            count++;
        }
        while(count>=left && count<=right){
            s.push(curr);
            curr=curr->next;
            nextt=curr;
            count++;
        }
        ListNode*revN=prev;
        // if(left==1){}
        while(!s.empty()){
            // ListNode*rev=s.top();
            prev->next=s.top();
            prev=prev->next;
            s.pop();
        }
        prev->next=nextt;

        return (left==1)? revN->next : head;
    }
};