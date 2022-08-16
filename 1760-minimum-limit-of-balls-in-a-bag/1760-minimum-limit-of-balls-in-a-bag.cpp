class Solution {
public:
    
    // minimize the maximum
    // binary search on answer
    // if x is possible, then anything above x is also possible, so try for below x
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1;
        int hi = 1e9;
        int ans;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int cnt = 0;
            for(auto val:nums) {
                cnt+=((val+mid-1)/mid) -1;
            }
            if(cnt<=maxOperations){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }
        return ans;
    }
};