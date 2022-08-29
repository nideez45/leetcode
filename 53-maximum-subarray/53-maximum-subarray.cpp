class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int dp[n];
        dp[0] = max(0,nums[0]);
        for(int i=1;i<n;i++){
            dp[i] = max({dp[i-1]+nums[i],nums[i],0});
            if(dp[i]!=0 || nums[i] == 0)ans = max(ans,dp[i]);
        }
        return ans;
        }
};