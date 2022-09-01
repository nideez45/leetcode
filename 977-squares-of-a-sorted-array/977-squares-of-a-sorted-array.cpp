class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int k = nums.size()-1;
        vector<int> ans(nums.size());
        while(l<=r){
            if(abs(nums[l]) < nums[r]){
                ans[k--] = nums[r]*nums[r];
                r--;
            }
            else{
                ans[k--] = nums[l]*nums[l];
                l++;
            }
        }
        return ans;
    }
};