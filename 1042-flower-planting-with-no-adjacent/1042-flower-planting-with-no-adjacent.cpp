class Solution {
public:
    
    vector<int> g[10005];
    int visited[100005];
    int col[100005];
    
    void dfs(int v){
        visited[v] = 1;
        
        set<int> st;
        for(int i=1;i<=4;i++) st.insert(i);
        
        for(int child:g[v]){
            if(visited[child]) st.erase(col[child]);
        }
        col[v] = *st.begin();
        
        for(int child:g[v]){
            if(!visited[child]) dfs(child);
        }
        
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        for(auto e:paths){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }   
        for(int i=1;i<=n;i++){
            if(visited[i] == 0){
                dfs(i);
            }
        }
        
        vector<int> ans;
        for(int i=1;i<=n;i++) ans.push_back(col[i]);
        return ans;
    }
};