class TrieNode{
    public:
    char data;
    bool isTerminal;

    unordered_map<char, TrieNode*> children;
    TrieNode(char val){
        data = val;
        isTerminal=false;
    }
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode('-'); 
    }
    void insertintoTrie(TrieNode*root, string word) {
               if(word.size()==0 ){
                root->isTerminal = true;
                return;
               }
              char ch = word[0];
              TrieNode* child;
              if(root->children.find(ch)!=root->children.end()){
                child = root->children[ch];
              }else{
                child = new TrieNode(ch);
                root->children[ch]=child; 
              }
              insertintoTrie(child,word.substr(1));
    }
   
    bool wordserach(TrieNode*root,string word){
        if(word.size()==0){
           return root->isTerminal;
        }
        char ch = word[0];
        TrieNode* child;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }else{
            return false;
        }
        bool ans = wordserach(child,word.substr(1));
        return ans;
    }

      bool serachprefix(TrieNode*root,string word){
        if(word.size()==0){
           return true;
        }
        char ch = word[0];
        TrieNode* child;
        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }else{
            return false;
        }
        bool ans = serachprefix(child,word.substr(1));
        return ans;
    }



    void insert(string word) {
         insertintoTrie(root,word);
    }
    bool search(string word) {
       return wordserach(root,word);

    }
    bool startsWith(string prefix) {
        return serachprefix(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */