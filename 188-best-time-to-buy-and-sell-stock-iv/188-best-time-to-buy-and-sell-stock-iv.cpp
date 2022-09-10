class Solution {
public:
    // state - konsa day, buy or sell, transactions left
    int dp[1010][2][101];
    vector <int> prices;
    int n;
    
    int rec(int level,int buy,int left){
        if(level == n) return 0;
        
        // transaction bacha nhi but ab buy krna hai toh 0
        if(left == 0 && buy) return 0;
        if(dp[level][buy][left] != -1) return dp[level][buy][left];
        int ans = 0;
        if(buy){
            // buy now or skip, if buy transaction left reduced by 1
            ans = max(-prices[level]+rec(level+1,0,left-1),rec(level+1,1,left));
        }
        else{
            // sell now or skip
            ans = max(prices[level]+rec(level+1,1,left),rec(level+1,0,left));
        }
        return dp[level][buy][left] = ans;
    }
    int maxProfit(int k, vector<int>& _prices) {
        prices = _prices;
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,1,k);
    }
};