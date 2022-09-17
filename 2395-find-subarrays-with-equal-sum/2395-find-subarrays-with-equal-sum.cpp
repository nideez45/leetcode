class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        //if(n == 2) return false;
        for(int i=0;i<n-1;i++){
            int a = nums[i]+nums[i+1];
            for(int j=i+1;j<n-1;j++){
                int b = nums[j]+nums[j+1];
                if(a == b) return true;
            }
        }
        return false;
    }
};