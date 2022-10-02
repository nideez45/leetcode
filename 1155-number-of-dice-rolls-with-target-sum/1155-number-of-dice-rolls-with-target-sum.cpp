class Solution {
public:
    int n,k;
    const int mod = 1e9+7;
    
    int dp[31][1001];
    
    int rec(int level,int sum_left){
        if(sum_left<0) return 0;
        if(level == n){
            return sum_left == 0;
        }
        if(dp[level][sum_left] != -1) return dp[level][sum_left];
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans+=rec(level+1,sum_left-i);
            ans%=mod;
        }
        return dp[level][sum_left] = ans;
    }
    
    int numRollsToTarget(int _n, int _k, int target) {
        n = _n;
        k = _k;
        memset(dp,-1,sizeof(dp));
        return rec(0,target);
    }
};