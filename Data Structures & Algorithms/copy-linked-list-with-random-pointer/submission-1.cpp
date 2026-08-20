/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*>m;
        if(head==NULL)return head;
        Node* newNode = new Node(head->val);
        Node* oldptr = head->next;
        Node* newptr = newNode;
        m[head]=newNode;
        while(oldptr!=NULL){
           Node * cp = new Node(oldptr->val);
           m[oldptr]=cp;
           newptr ->next = cp;
           newptr = newptr->next;
           oldptr= oldptr->next;

        }
         Node * oldtemp = head;
         Node * newtemp = newNode;
         while(oldtemp!=NULL){
            newtemp->random = m[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
         }
         return newNode;
    }
};
