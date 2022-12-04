class Solution {
public:
    
    vector<int> g[100005];
    int visited[100005];
    
    void dfs(int v){
        visited[v] = 1;
        for(int child:g[v]){
            if(!visited[child]) dfs(child);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {

        int ans = 1e5;
        for(auto e:roads){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(1);
        for(auto e:roads){
            if(visited[e[0]]) ans = min(ans,e[2]);
        }
        return ans;
    }
};