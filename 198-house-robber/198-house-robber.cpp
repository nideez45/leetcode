class Solution {
public:
    
    
    // Concept = Dynamic programming
    // Time - O(n), Space - O(1)
    // either take current or dont take
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prevtaken = nums[0];
        int prevnot = 0;
        for(int i=1;i<n;i++){
            int curtaken = nums[i]+prevnot;
            int curnot = max(prevtaken,prevnot);
            prevnot = curnot;
            prevtaken = curtaken;
        }
        return max(prevnot,prevtaken);
    }
};