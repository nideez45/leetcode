class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int ans;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            bool ok = false;
            if(mid == 0) ok = true;
            else{
                if(nums[mid]>nums[mid-1]){
                    ok = true;
                }
            }
            if(ok){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
};