class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = 1e6+5;
        int ans;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int sm = 0;
            for(auto val:nums) sm+=((val+mid-1)/mid);
            if(sm<=threshold){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};