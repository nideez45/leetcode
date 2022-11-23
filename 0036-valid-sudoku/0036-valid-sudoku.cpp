class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        for(int i=0;i<n;i++){
            int mask = 0;
            for(int j=0;j<n;j++){
                if(board[i][j] == '.') continue;
                if((mask&(1<<(board[i][j]-'0')))) return false;
                mask^=(1<<(board[i][j]-'0'));
            }
        }
        
        for(int i=0;i<n;i++){
            int mask = 0;
            for(int j=0;j<n;j++){
                  if(board[j][i] == '.') continue;
                if((mask&(1<<(board[j][i]-'0')))) return false;
                mask^=(1<<(board[j][i]-'0'));
            }
        }
    
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                int mask = 0;
                for(int x = i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                         if(board[x][y] == '.') continue;
                         if((mask&(1<<(board[x][y]-'0')))) {
                             cout<<x<<" "<<y;
                             return false;
                         }
                         mask^=(1<<(board[x][y]-'0'));
                    }
                }
            }
        }
        return true;
    }
};