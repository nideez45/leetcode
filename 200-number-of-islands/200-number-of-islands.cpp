class Solution {
public:
    
    int visited[301][301];
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<char>> grid;
    
    bool check(int x,int y){
        int n = grid.size();
        int m = grid[0].size();
        return (x>=0 && y>=0 && x<n && y<m);
    }
    
    void dfs(int x,int y){
        if(!check(x,y) || grid[x][y] == '0' || visited[x][y] == 1) return;
        visited[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            dfs(nx,ny);
        }
    }
    
    int numIslands(vector<vector<char>>& _grid) {
        grid = _grid;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};