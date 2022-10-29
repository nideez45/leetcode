class Solution {
public:
    
    
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        int n = plantTime.size();
        for(int i=0;i<n;i++){
            v.push_back({growTime[i],plantTime[i]});
        }
        sort(v.rbegin(),v.rend());
        int ans = 0;
        int pc = 0;
        for(int i=0;i<n;i++){
            pc+= v[i].second;
            ans = max(ans,pc+v[i].first+1);
        }
        return ans-1;
    }
};