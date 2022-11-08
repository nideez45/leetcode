class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> all_perm;
    vector<int> cur_perm;
    map<int,int> mp;
    
    void rec(int level){
        if(level == n){
            all_perm.push_back(cur_perm);
            return;
        }
        
        // take choice
        for(int i=0;i<n;i++){
            if(mp[i] == 0){
                mp[i] = 1;
                cur_perm.push_back(nums[i]);
                rec(level+1);
                cur_perm.pop_back();
                mp[i]=0;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        rec(0);
        return all_perm;
    }
};