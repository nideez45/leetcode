class Solution {
public:
    
    // concept - dynamic programming
    // can also be done with combinatorics
    // to reach bootom right corner we have to make right move rows-1 times
    // and down move column-1 times, so its just (rows+columns-2) C (rows-1)
    
    int dp[101][101];
    
    int rec(int x,int y,int n,int m){
        if(x<=0 || y<=0) return 0;
        if(x == 1 || y == 1) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        int ans = rec(x-1,y,n,m)+rec(x,y-1,n,m);
        return dp[x][y] = ans;
    }
    
    int uniquePaths(int n, int m) {
        memset(dp,-1,sizeof(dp));
        return rec(n,m,n,m);
    }
};