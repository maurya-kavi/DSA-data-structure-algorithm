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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};

        vector<int>v; // store the position of the critical point
        ListNode*cur=head;
        int pos=1;
        ListNode*prev=cur;
        cur=cur->next;
        while(cur && cur->next){
            ListNode*next=cur->next;
            if(cur->val>prev->val && cur->val>next->val) {
                v.push_back(pos);
            }
            else if(cur->val<prev->val && cur->val<next->val){
                v.push_back(pos);
            }

            pos++;

            prev=cur;
            cur=cur->next;
        }

        if(v.size()<2) return {-1,-1};

        int maxdis=v[v.size()-1]-v[0];

        int mindis=INT_MAX;
        for(int i=1; i<v.size(); i++){
            int x=v[i]-v[i-1];
            mindis=min(mindis,x);
        }

        return {mindis,maxdis};
    }
};