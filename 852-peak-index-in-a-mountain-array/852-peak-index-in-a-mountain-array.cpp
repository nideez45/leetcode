class Solution {
public:
    
    // 1 2 3 4 5 4 3 2 1
    // 1 1 1 1 1 0 0 0 0 
    
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        int ans;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(mid == 0 || (arr[mid]>arr[mid-1])){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};