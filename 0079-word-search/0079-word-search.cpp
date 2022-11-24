class Solution {
public:
    vector <vector<char>> board;
    string word;
    int n;
    int m;
    int N;
    bool visited[6][6];
    
    bool check(int x,int y){
        if(x>=0 && y>=0 && x<n && y<m && visited[x][y] == false) return true;
        return false;
    }
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    bool ans = false;
    
    void rec(int x,int y,int cur){
       
        if(board[x][y] == word[cur]){
            visited[x][y] = 1;
            for(int i=0;i<4;i++){
                if(check(x+dx[i],y+dy[i])) {
                    rec(x+dx[i],y+dy[i],cur+1);
                }
            }
            if(cur == N-1) ans = true;
            visited[x][y] = 0;
        }
    }
    
    bool exist(vector<vector<char>>& _board, string _word) {
        board = _board;
        word = _word;
        n = board.size();
        m = board[0].size();
        if(n*m< word.size()) return 0;
        
        N = word.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 rec(i,j,0);
                if(ans) break;
        }
    }
        return ans;
    }
};