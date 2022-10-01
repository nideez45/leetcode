class Solution {
public:
    
    int dp[105];
    string s;
    int n;
    
    int rec(int level){
        if(level == n) return 1;
        if(dp[level] != -1) return dp[level];
        int ans = 0;
        if(level<n && s[level] != '0'){
            ans+=rec(level+1);
        }
        if(level+1<n){
            if((s[level] == '1') || (s[level] == '2' && s[level+1]<='6')){
                ans+=rec(level+2);
            }
        }
        return dp[level] = ans;
        
    }
    
    
    int numDecodings(string _s) {
        s = _s;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return rec(0);
    }
};