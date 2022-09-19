class Solution {
public:
    
    
    bool check(vector<int>&nums,int k,int m){
        int cur = 0;
        int cnt = 0;
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i]>k) return false;
            if(cur+nums[i]<=k){
                cur+=nums[i];
            }
            else{
                cur = nums[i];
                cnt++;
            }
            i++;
        }
        return cnt<=m-1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int lo = 0;
        int hi = 1e9+5;
        int ans;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(nums,mid,m)){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }
        return ans;
    }
};