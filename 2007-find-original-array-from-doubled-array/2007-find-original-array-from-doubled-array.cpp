class Solution {
public:
    
    // 1 2 3 4 6 8
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        int n = changed.size();
        vector<int> visited(n,0);
        vector<int> ans;
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[changed[i]].push_back(i);
        }
        bool ok = true;
        for(int i=n-1;i>=0;i--){
            if(visited[i]) continue;
            int x = changed[i];
            if(x == 0){
                if(mp[0].size() == 0){
                    ok = false;
                    break;
                }
                else{
                    mp[0].pop_back();
                }
            }
            if(x%2 == 1 || mp[x/2].size() == 0) {
                ok = false;
                break;
            }
            visited[i] = 1;
            visited[mp[x/2].back()] = 1;
            mp[x/2].pop_back();
            ans.push_back(x/2);
        }
        if(ok == false){
            return {};
        }
        return ans;
    }
};