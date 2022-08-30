class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 1e9;
        int ans_sum;
        for(int j=0;j<n;j++){
            int i=0;
            int k = n-1;
            while(i<j && j<k){
                int sm = nums[i]+nums[j]+nums[k];
                if(ans>abs(sm-target)){
                    ans = abs(sm-target);
                    ans_sum = sm;
                }
                if(sm<target){
                    i++;
                }
                else k--;
            }
        }
        
        return ans_sum;
    }
};