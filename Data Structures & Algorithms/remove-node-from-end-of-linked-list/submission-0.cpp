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
        int cnt =0;
        ListNode* t = head;
        while(t!=NULL){
            cnt++;
            t=t->next;
        }
         if (cnt == n) {
            return head->next;
        }
        int tra = cnt - n-1;
        ListNode * curr = head;
        while(tra--){
            curr=curr->next;
        }
        ListNode* nex = curr->next->next;
        curr->next=nex;
        return head;
    }
};
