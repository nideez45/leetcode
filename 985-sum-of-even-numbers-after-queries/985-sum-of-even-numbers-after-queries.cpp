class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for(auto val:nums){
            if(val%2 == 0) sum+=val;
        }
        for(auto q:queries){
            int old = nums[q[1]];
            int now = nums[q[1]] + q[0];
            if(old%2 == 0){
                sum-=old;
            }
            if(now%2 == 0){
                sum+=now;
            }
            ans.push_back(sum);
            nums[q[1]] += q[0];
        }
        return ans;
    }
};