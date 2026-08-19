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
      ListNode* reverse(ListNode* head){
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr=forward;
        }
        return prev;
      }
    void reorderList(ListNode* head) {
     ListNode* slow = head;
     ListNode* fast = head;
     while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
     }
     ListNode * sec = reverse(slow->next);
     slow->next=NULL;
    
    while(head && sec){
        ListNode* temp1 = head->next;
        ListNode *temp2 = sec->next;
        head->next = sec;
        sec->next = temp1;
        head = temp1;
        sec = temp2;
    }
    }
};
