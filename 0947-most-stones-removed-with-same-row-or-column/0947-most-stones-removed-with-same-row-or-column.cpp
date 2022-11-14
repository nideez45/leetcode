class Solution {
public:
    
    int parent[1005];
    int sz[1005];
    
    void makeset(int v){
        parent[v] = v;
        sz[v] = 1;
    }
    
    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[a]>sz[b]) swap(a,b);
        sz[b]+=sz[a];
        parent[a] = b; 
        return;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for(int i=0;i<n;i++) makeset(i);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1])){
                    Union(i,j);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(find(i) == i) ans += sz[i]-1;
        }
        return ans;
    }
};