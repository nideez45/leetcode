class Solution {
public:
    
    // Time O(nlogn) and Space O(n)
    
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(temp.empty() || nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(temp.begin(),temp.end(),nums[i]);
                *it = nums[i];
            }
        }
        return temp.size();
    }
};