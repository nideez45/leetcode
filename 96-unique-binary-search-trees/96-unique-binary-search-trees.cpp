class Solution {
public:
    
    // 1 2 3 .... n
    // for each number everything before it should be part of the left subtree
    // everything after the number should be part of right subtree
    
    int dp[20];
    
    int n;
    
    int rec(int cnt){
        if(cnt == 1 || cnt == 0) return 1;
        if(dp[cnt] != -1) return dp[cnt];
        
        int ans = 0;
        for(int i=1;i<=cnt;i++){
         ans += rec(i-1)*rec(cnt-i);
        }
        return dp[cnt] = ans;
    }
    
    int numTrees(int _n) {
        n = _n;
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans+=rec(i-1)*rec(n-i);
        }
        return ans;
    }
};