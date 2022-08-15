class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        // first finding max sum subarray without circular
        int ans = -1e9;
        int sm = 0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            ans = max(ans,sm);
            if(sm<0){
                sm = 0;
            }
        }
        int total_sum = 0;
        for(auto val:nums) total_sum+=val;
        // now we have to also consider circular
        int best = nums[0]; // best leftsum till now
        int presum = nums[0];
        for(int i=1;i<n;i++){
            int right_sum = total_sum-presum;
            ans = max(ans,right_sum+best);
            presum+=nums[i];
            best = max(best,presum);
        }
        return ans;
    }
};