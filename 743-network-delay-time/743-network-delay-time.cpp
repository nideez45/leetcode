class Solution {
public:
    
    int dist[105];
    bool vis[105];
    vector <pair<int,int>> g[105];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i=1;i<=n;i++){
            dist[i] = 1e9;
            vis[i] = 0;
        }
        for(auto &v:times){
            int x = v[0];
            int y = v[1];
            int c = v[2];
            g[x].push_back({y,c});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            if(p.first>dist[p.second]) continue;
           // cout<<p.second<<" "<<p.first<<'\n';
            for(auto neigh:g[p.second]){
                if(dist[neigh.first]>p.first+neigh.second){
                    dist[neigh.first] = p.first+neigh.second;
                    pq.push({dist[neigh.first],neigh.first});
                }
            }
        }
        for(int i=1;i<=n;i++) if(dist[i] == 1e9) return -1;
        int ans = 0;
        for(int i=1;i<=n;i++) ans = max(ans,dist[i]);
        return ans;
    }
};