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
    // struct compare{
    //     bool operator()(ListNode*a , ListNode*b){
    //         return a->val > b->val; //min heap
    //     }
    // };
    static bool compare(const ListNode*a, const ListNode*b){
        return a->val > b->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,decltype(&compare)>pq(compare);
        int n=lists.size();
        //push the head of all lists in pq, all list are in sorted
        for(int i=0; i<n; i++){
            if(lists[i]) pq.push(lists[i]);
        }
        ListNode*startNode=new ListNode(0);
        ListNode*tail=startNode;

        while(!pq.empty()){
            ListNode*curr=pq.top();
            pq.pop();
            tail->next=curr;
            tail=tail->next;

            if(curr->next){
                pq.push(curr->next);
            }
        }
        return startNode->next;
    }
};