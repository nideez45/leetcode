class Solution {
public:
    
    // state - current index, k left
    
    int dp[202][202];
    vector<int> nums;
    int n;
    
    int rec(int level,int kleft){
        if(kleft == 0 && level!=n){
            return 1e9;
        }
        if(level == n){
            if(kleft == 0) return 0;
            return 1e9;
        }
        if(dp[level][kleft] != -1){
            return dp[level][kleft];
        }
        int ans = 1e9;
        int mx = 0;
        int sm = 0;
        for(int i=0;i<n;i++){
            if(level+i>=n) break;
            // level to level+i
            sm += nums[level+i];
            mx = max(mx,nums[level+i]);
            ans = min(ans,rec(level+i+1,kleft-1) + (i+1)*mx - sm);
        }
        return dp[level][kleft] = ans;
    }
    
    int minSpaceWastedKResizing(vector<int>& _nums, int k) {
        nums = _nums;
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,k+1);
    }
};