class Solution {
public:
    // dp1 = length of lis ending at i
    // dp2 = number of lis ending at i
    
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp1[n];
        int dp2[n];
        for(int i=0;i<n;i++){
            dp1[i] = dp2[i] = 1;
        }
        for(int i=1;i<n;i++){
            int x = nums[i];
            for(int j=0;j<i;j++){
                if(x>nums[j]){
                    if(1+dp1[j]>dp1[i]){
                        dp1[i] = 1+dp1[j];
                        dp2[i] = dp2[j];
                    }
                    else if(1+dp1[j] == dp1[i]){
                        dp2[i] += dp2[j];
                    }
                }
            }
        }
        int x = *max_element(dp1,dp1+n);
        int ans = 0;
        for(int i=0;i<n;i++)if(dp1[i] == x) ans+=dp2[i];
        return ans;
    }
};