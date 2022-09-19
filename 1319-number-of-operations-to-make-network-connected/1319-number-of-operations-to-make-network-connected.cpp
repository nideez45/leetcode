class Solution {
public:
    
    // need number of excess edges in each component and number of components
    
    vector<int> g[100005];
    
    int deg = 0;
    int cnt = 0;
    
    int visited[100005];
    
    void dfs(int v){
        visited[v] = 1;
        deg+=g[v].size();
        cnt++;
        for(int child:g[v]){
            if(!visited[child]){
                dfs(child);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        for(auto e:connections){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int excess = 0;
        int comp_cnt = 0;
        for(int i=0;i<=n-1;i++){
            if(visited[i] == 0){
                comp_cnt++;
                deg = 0;
                cnt = 0;
                dfs(i);
                excess+=(deg/2 - (cnt-1));
            }
        }
        if(excess>=comp_cnt-1) return comp_cnt-1;
        else return -1;
    }
};