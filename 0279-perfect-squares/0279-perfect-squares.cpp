class Solution {
public:
    
    int dp[10001];
    
    int func(int n){
        if(n == 0) return 0;
        int ans = 10000;
        if(dp[n] !=-1) return dp[n];
        for(int i=1;i<=100;i++){
            if(n - i*i>=0){
            ans = min(ans,1+func(n - i*i));
            }
        }
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        for(int i=0;i<=10000;i++) dp[i]=-1;
        return func(n);
    }
};