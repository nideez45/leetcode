

int dp[1<<15];
    int n;
    
    int rec(int level,int mask){
        if(level == n){
            return 1;
        }
        if(dp[mask] != -1) return dp[mask];
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))){
                if((level+1)%(i+1) == 0 || (i+1)%(level+1) == 0){
                    int temp_mask = mask^(1<<i);
                    ans+=rec(level+1,temp_mask);
                }
            }
        }
        return dp[mask] = ans;
    }
    
    int countArrangement(int _n) {
        n = _n;
        memset(dp,-1,sizeof(dp));    
        return rec(0,0);
    }