/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
    
        int n = mountainArr.length();
        // first find the index of peak element
        // then the array is separated as two sorted array , perform binary search in both
        // the sorted arrays to get the smallest index
        int ans;
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(mid == 0 || mountainArr.get(mid)>mountainArr.get(mid-1)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        // 0 to ans, sorted in increasing order
        // ans+1 to n-1 sorted in decreasing order
        
        // first checking in 0 to ans
        lo = 0;
        hi = ans;
        int ans1 = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int x = mountainArr.get(mid);
            if(x == target){
                ans1 = mid;
                break;
            }
            else if(x>target){
                hi = mid-1;
            }
            else lo = mid+1;
        }
        if(ans1 !=-1) return ans1;
        lo = ans+1;
        hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int x = mountainArr.get(mid);
            if(x == target){
                return mid;
            }
            else if(x>target){
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return -1;
    }
};