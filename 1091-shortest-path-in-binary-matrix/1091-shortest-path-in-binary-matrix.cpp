class Solution {
public:
    
    vector <vector<int>> grid;
    
    vector <pair<int,int>> dir = {
        {-1,-1},{1,1},{-1,1},{1,-1},
        {1,0},{0,1},{-1,0},{0,-1}
    };
    
    int dist[101][101];
    int n,m;
    bool check(int x,int y){
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y] == 1) return false;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& _grid) {
        grid = _grid;
        n = grid.size();
        m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        if(n == 1 && m==1) return 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j] = 1e9;
            }
        }
        
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0] = 0;
        while(!q.empty()){
            pair<int,int> k = q.front();
            q.pop();
            for(auto mov:dir){
                int nx = k.first+mov.first;
                int ny = k.second+mov.second;
                if(check(nx,ny) && dist[nx][ny]>1+dist[k.first][k.second]){
                    dist[nx][ny] = 1+dist[k.first][k.second];
                    if(nx == n-1 && ny == m-1) return dist[nx][ny]+1;
                    q.push({nx,ny});
                }
            }
        }
        return -1;
    }
};