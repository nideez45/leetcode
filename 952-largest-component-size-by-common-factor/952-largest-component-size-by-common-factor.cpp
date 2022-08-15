class Solution {
public:
    
    int parent[100005];
    int sz[100005];
    const int N = 1e5+5;
    void makeset(int v){
        parent[v] = v;
        sz[v] = 1;
    }
    
    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    void Union(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x]>sz[y]) swap(x,y);
        sz[y]+=sz[x];
        parent[x] = y;
    }
    
    int largestComponentSize(vector<int>& nums) {
        for(int i=1;i<N;i++) makeset(i);
        int freq[N];
        for(int i=0;i<N;i++) freq[i] = 0;
        for(auto val:nums) freq[val]++;
        for(int i=2;i<N;i++){
            for(int j=i;j<N;j+=i){
                if(freq[j]){
                    Union(i,j);
                }
            }
        }
        int mx = 0;
        map<int,vector<int>> mp;
        for(auto val:nums){
            mp[find(val)].push_back(val);
        }
        for(auto pr:mp) mx = max(mx,(int)(pr.second).size());
        return mx;
    }
};