class Solution {
public:
    
    
    
    
    vector<pair<int,int>> g[100005]; // adjacency list
    vector<pair<int,int>> grev[100005];
    int n;
    const long long inf = 1e15 ;
    vector<long long> dijkstra(int src,int dest,vector<pair<int,int>> g[]){
        vector<long long> dist(n,inf);
        dist[src] = 0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,src}); // state - dist,node
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            long long d = p.first;
            int u = p.second;
            if(dist[u]<d) continue;
            for(auto child:g[u]){
                int v = child.first;
                long long wt = child.second;
                if(dist[v]>d+wt){
                    dist[v] = 1LL*d + 1LL*wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
    
    long long minimumWeight(int _n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        n = _n;
        for(auto e:edges){
            g[e[0]].push_back({e[1],e[2]});
            grev[e[1]].push_back({e[0],e[2]});
        }
       vector<long long> dist1 = dijkstra(src1,dest,g);
        vector<long long> dist2 = dijkstra(src2,dest,g);
        vector<long long> dist3 = dijkstra(dest,src1,grev);
       // for(int i=0;i<n;i++) cout<<i<<" "<<dist2[i]<<'\n';
        long long ans = 1e15;
        for(int i=0;i<n;i++){
            ans = min(ans,dist1[i]+dist2[i]+dist3[i]);
        }
        if(ans == 1e15) ans = -1;
        return ans;
    }
};