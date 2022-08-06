class Solution {
public:
    const int mod = 1e9+7;
    int dp[100005];
    string s;
    int n;
    int k;
    
    int rec(int level){
        if(level == n){
            return 1;
        }
        if(s[level] == '0') return 0;
        if(dp[level] != -1) return dp[level];
        int ans = 0;
        for(int i=1;i<=10;i++){
            if(level+i>n) break;
            if(stoll(s.substr(level,i)) <= 1LL*k){
                ans+=rec(level+i);
                ans%=mod;
            }
        }
        return dp[level] = ans;
    }
    
    int numberOfArrays(string _s, int _k) {
        s = _s;
        k = _k;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return rec(0);
    }
};