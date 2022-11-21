class Solution {
public:
    
    // if x people are at node u and there is an edge from u to v in direction of going to 0
    // then the contribution of u-v edge will be ceil(x/seats)
    
    vector<int> g[100005];
    
    long long ans = 0;
    int seats;
    
    int dfs(int v,int par){
        int total = 0;
       for(int child:g[v]) {
           if(child == par) continue;
           int temp = dfs(child,v);
           total += temp;
           // child to v edge contribution
           ans += (1LL*temp+1LL*seats-1LL)/seats;
       }
        return total+1;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int _seats) {
        seats = _seats;
        for(auto e:roads){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0,-1);
        return ans;
    }
};