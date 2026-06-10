class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Find the middle (The Tortoise and the Hare)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse the second half of the chain
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* left = head;
        ListNode* right = prev; 
        
        while (right) {
            if (left->val != right->val) {
                return false; 
            }
            left = left->next;
            right = right->next;
        }

        return true; 
    }
};