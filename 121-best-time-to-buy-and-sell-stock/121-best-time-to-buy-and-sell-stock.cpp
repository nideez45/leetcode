class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        int mx = prices[n-1];
        int ans = 0;
        for(int i=n-2;i>=0;i--){
            if(mx-prices[i]>ans){
                ans = mx-prices[i];
            }
            mx = max(mx,prices[i]);
        }
        return ans;
    }
};