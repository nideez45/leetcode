class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> nums;
    int n;
    
    // at each index, there is a choice to take or dont take
    void rec(int level){
        
        // all choices were made
        if(level == n){
            ans.push_back(temp);
            return;
        }
        
        // take
        temp.push_back(nums[level]);
        rec(level+1);
        temp.pop_back();
        
        // dont take
        // if i dont take a value then i go to the index which is not same as value
        int idx = level;
        while(idx<n && nums[idx]==nums[level])idx++;
        rec(idx);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        sort(nums.begin(),nums.end());
        rec(0);
        return ans;
    }
};