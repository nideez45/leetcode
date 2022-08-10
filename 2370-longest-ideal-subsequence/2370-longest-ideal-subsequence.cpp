class Solution {
public:
    string s;
    int n;
    int k;
    
    int dp[100005][27];
    
    int rec(int level,int prev){
        if(level == n) return 0;
        if(dp[level][prev] != -1) return dp[level][prev];
        
        // skip current
        int ans = rec(level+1,prev);
        if(prev == 26){
            ans = max(ans,1+rec(level+1,s[level]-'a'));
        }
        else{
            if(abs(prev-(s[level]-'a')) <=k){
                ans = max(ans,1+rec(level+1,s[level]-'a'));
            }
        }
        return dp[level][prev] = ans;
    }
    
    int longestIdealString(string _s, int _k) {
        s = _s;
        k = _k;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,26);
    }
};