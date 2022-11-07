class Solution {
public:
    
    vector<int> nums;
    int n;
    vector<int> Set;
    vector<vector<int>> power_set;
    
    void rec(int level){
        if(level==n){
            power_set.push_back(Set);
            return;
        } 
        // choice of not taking
        rec(level+1);
        
        // if taking
        Set.push_back(nums[level]);
        rec(level+1);
        Set.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        rec(0);
        return power_set;
    }
};