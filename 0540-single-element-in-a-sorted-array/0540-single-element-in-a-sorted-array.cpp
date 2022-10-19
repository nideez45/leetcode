class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans;
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int rem = n-mid;
            if(rem%2 == 0){
                if(nums[mid+1] == nums[mid]){
                    hi = mid-1;
                }
                else{
                    ans = mid;
                    lo = mid+1;
                }
            }
            else{
                if(mid!=0 && nums[mid] == nums[mid-1]){
                    hi = mid-1;
                }
                else{
                    ans = mid;
                    lo = mid+1;
                }
            }
        }
        return nums[ans];
    }
};