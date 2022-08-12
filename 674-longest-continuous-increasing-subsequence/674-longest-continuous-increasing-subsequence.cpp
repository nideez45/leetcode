class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int i=0;
        int n = nums.size();
        while(i<n){
            int cnt = 1;
            int x = nums[i];
            i++;
            while(i<n && nums[i]>x){
                x = nums[i];
                i++;
                cnt++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};