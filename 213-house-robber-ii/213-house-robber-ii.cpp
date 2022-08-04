class Solution {
public:
    
    // extending soln of house robber 1
    // only change here is cant choose 1st and last together
    // so take best of 1 to n-1 and 2 to n
    
    int helper(vector<int>& nums,int l,int r) {
        int prevtaken = nums[l];
        int prevnot = 0;
        for(int i=l+1;i<r;i++){
            int curtaken = nums[i]+prevnot;
            int curnot = max(prevtaken,prevnot);
            prevnot = curnot;
            prevtaken = curtaken;
        }
        return max(prevnot,prevtaken);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // edge case
        if(n == 1) return nums[0];
        return max(helper(nums,1,n),helper(nums,0,n-1));
    }
};