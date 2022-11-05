struct node{
    node* child[26];
    bool wordend = false;
    node(){
        for(int i=0;i<26;i++) child[i] = NULL;
    }
};


class Solution {
public:
    struct node* root = new node();
    
    void insert(string s){
        struct node* cur = root;
        for(int i=0;i<s.size();i++){
            int x = s[i]-'a';
            if(cur->child[x] == NULL) cur->child[x] = new node();
            cur = cur->child[x];
        }
        cur->wordend = true;
    }
    
    vector<string> ans;
    vector<vector<char>> board;
    int visited[13][13];
    string temp;
    int n,m;
    
    bool inside(int x,int y){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    
    void rec(int i,int j,struct node* cur){
        if(cur->wordend == true){
            ans.push_back(temp);
            cur->wordend = false;
        }
        
        if(!inside(i,j) || visited[i][j]) return;
        
        
        int x = board[i][j]-'a';
        if(cur->child[x] != NULL){
            temp.push_back(board[i][j]);
            visited[i][j] = 1;
            rec(i+1,j,cur->child[x]);
            rec(i-1,j,cur->child[x]);
            rec(i,j-1,cur->child[x]);
            rec(i,j+1,cur->child[x]);
            visited[i][j] = 0;
            temp.pop_back();
        }
    }
    
    
    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        for(auto s:words) insert(s);
        board = _board;
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rec(i,j,root);
            }
        }
        
        return ans;
    }
};