class Solution {
public:
    
    vector<vector<int>> intervals;
    int n;
    int dp[100000];
    
    int rec(int level){
        if(level == n){
            return 0;
        }
        if(dp[level] != -1) return dp[level];
        
        // skip this
        int ans = rec(level+1);
        vector<int> p = {intervals[level][1],-1,0};
        auto idx = lower_bound(intervals.begin(),intervals.end(),p)-intervals.begin();
        ans = max(ans,intervals[level][2]+rec(idx));
        return dp[level] = ans;
        
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            intervals.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(intervals.begin(),intervals.end());
       // for(auto val:intervals) cout<<val[2]<<'\n';
        return rec(0);
    }
};