class Solution {
public:
    
    // concept - breadth first search
    
    vector<int> g[100005];
    const int inf = 1e9;
    vector<int> bfs(int source,int n){
        vector<int> dist(n,inf);
        dist[source] = 0;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(int child:g[k]){
                if(dist[child]>1+dist[k]){
                    dist[child] = 1+dist[k];
                    q.push(child);
                }
            }
        }
        return dist;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        for(int i=0;i<n;i++){
            if(edges[i] != -1) g[i].push_back(edges[i]);
        }
        vector<int> dist1 = bfs(node1,n);
        vector<int> dist2 = bfs(node2,n);
        int ans_node = -1;
        int ans = 1e9;
        for(int i=0;i<n;i++){
            if(dist1[i] == inf || dist2[i] == inf)continue;
            int temp = max(dist1[i],dist2[i]);
            if(temp<ans){
                ans = temp;
                ans_node = i;
            }
        }
        return ans_node;
    }
};