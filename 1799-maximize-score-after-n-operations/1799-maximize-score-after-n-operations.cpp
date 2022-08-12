class Solution {
public:
    
    vector<int> nums;
    int n;
    int dp[8][1<<14];
    
    int rec(int level,int mask){
        if(level == n+1){
            return 0;
        }
        if(dp[level][mask] != -1) return dp[level][mask];
        
        int ans = 0;
        
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){
                if(i == j) continue;
                if((mask&(1<<i)) || (mask&(1<<j))) continue;
                int temp_mask = ((mask^(1<<i))^(1<<j));
                ans = max(ans,level*(__gcd(nums[i],nums[j])) + rec(level+1,temp_mask));
            }
        }
        
        return dp[level][mask] = ans;
    }
    
    int maxScore(vector<int>& _nums) {
        nums = _nums;
        n = nums.size()/2;
        memset(dp,-1,sizeof(dp));
        return rec(1,0);
    }
};