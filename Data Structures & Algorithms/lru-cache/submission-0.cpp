class LRUCache {
public:
class Node{
    public:
    int key , val;
    Node* prev;
    Node* next;
    Node(int k , int v){
        key = k;
        val = v;
        prev=next=NULL;
    }
};
    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);
    unordered_map<int,Node*>mp;
    int limit;
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
       if(mp.find(key)==mp.end()){
        return -1;
       }
      int  ans = mp[key]->val;
      Node* ansNode = mp[key];
       mp.erase(key);
       deleteNode(ansNode);
       addNode(ansNode);
       mp[key]=ansNode;
       return ans;
    }
    
    void put(int key, int value) {
        Node* newNode = new Node(key,value);
        if(mp.find(key)!=mp.end()){
            Node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==limit){
            Node* temp=tail->prev;
            mp.erase(temp->key);
            deleteNode(temp);
        }
        addNode(newNode);
        mp[key]=newNode;
    }
    void deleteNode(Node * oldNode){
        Node *oldprev = oldNode->prev;
       Node * oldNext = oldNode->next;
        oldprev->next = oldNext;
        oldNext->prev = oldprev;
    }
    void addNode(Node* newNode){
        Node* temp = head->next;
        head ->next = newNode;
        temp->prev = newNode;
        newNode->next = temp;
        newNode->prev = head;
    }
};
