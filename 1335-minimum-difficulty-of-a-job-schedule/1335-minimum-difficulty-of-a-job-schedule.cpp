class Solution {
public:
    
    vector<int> jobs;
    int n;
    int dp[301][11];
    
    int rec(int level,int left){
        if(level == n){
            if(left == 0){
                return 0;
            }
            return 1e9;
        }
        if(left == 0) return 1e9;
        if(dp[level][left] != -1) return dp[level][left];
        int ans = 1e9;
        int mx = 0;
        for(int i=0;i<n;i++){
            if(level+i >= n)break;
            mx=max(mx,jobs[level+i]);
            ans = min(ans,mx+rec(level+i+1,left-1));
        }
        return dp[level][left] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        jobs = jobDifficulty;
        n = jobs.size();
        if(n<d) return -1;
        memset(dp,-1,sizeof(dp));
        return rec(0,d);
    }
};