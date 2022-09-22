class Solution {
public:
    
    bool inside(int x,int y,int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        int dist[n][n];
        int inf = 1e9;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) dist[i][j] = inf;
        bool ok = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    ok = true;
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        if(ok == false) return -1;
        while(!q.empty()){
            auto pr = q.front();
            q.pop();
            int x = pr.first;
            int y = pr.second;
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(inside(nx,ny,n) && dist[nx][ny]>1+dist[x][y]){
                    dist[nx][ny] = 1+dist[x][y];
                    q.push({nx,ny});
                }
            }
        }
        int mx = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) mx = max(mx,dist[i][j]);
            }
        }
        if(mx == inf) mx = -1;
        return mx;
    }
};