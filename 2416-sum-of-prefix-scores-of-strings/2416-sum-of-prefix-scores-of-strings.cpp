struct node{
    node* child[26];
    int prefix;
    
    node(){
        for(int i=0;i<26;i++) child[i] = NULL;
        prefix = 0;
    }
    
};



class Solution {
public:
    
    struct node* root = new node();
    
    void insert(string &word) {
        struct node* cur = root;
        for(auto c:word){
            int x = c-'a';
            if(cur->child[x] == NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
            cur->prefix++;
        }
       
    }
    
    int find(string &word){
        struct node* cur = root;
        int ans = 0;
        for(auto c:word){
            int x = c-'a';
            cur = cur->child[x];
            ans+=cur->prefix;
        }
        return ans;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto w:words) insert(w);
        vector<int> ans;
        int n = words.size();
        ans.assign(n,0);
        for(int i=0;i<n;i++){
            ans[i] = find(words[i]);
        }
        return ans;
    }
};