class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int mx = 0;
        vector<pair<int,int>> v;
        int cnt = 0;
        for(auto val:intervals){
            v.push_back({val[0],-1});
            v.push_back({val[1],1});
        }
        sort(v.begin(),v.end());
        for(auto event:v){
           // cout<<event.first<<" "<<event.second<<'\n';
            if(event.second == -1){
                cnt++;
                mx = max(mx,cnt);
            }
            else cnt--;
        }
        return mx;
    }
};