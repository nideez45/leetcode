struct node{
    node* child[26];
    bool wordend;
    int prefix;
    
    node(){
        for(int i=0;i<26;i++) child[i] = NULL;
        wordend = false;
        prefix = 0;
    }
    
};

class Trie {
public:
    struct node* root;
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        struct node* cur = root;
        for(auto c:word){
            int x = c-'a';
            if(cur->child[x] == NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
            cur->prefix++;
        }
        cur->wordend = true;
    }
    
    bool search(string word) {
        struct node* cur = root;
        for(auto c:word){
            int x = c-'a';
            if(cur->child[x] == NULL) return false;
            cur = cur->child[x];
        }
        return cur->wordend;
    }
    
    bool startsWith(string prefix) {
        struct node* cur = root;
        for(auto c:prefix){
            int x = c-'a';
            if(cur->child[x] == NULL) return false;
            cur = cur->child[x];
        }
        return (cur->wordend || cur->prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */