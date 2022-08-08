class Solution {
public:
    
    // dynamic programming
    // iterative code
    // Time - O(n^2) Space - O(n)
    // dp[i] -> length of lis ending at index i
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for(int i=0;i<n;i++) dp[i] = 1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]) dp[i] = max(dp[i],1+dp[j]);
            }
        }
        int x = *max_element(dp,dp+n);
        return x;
    }
};