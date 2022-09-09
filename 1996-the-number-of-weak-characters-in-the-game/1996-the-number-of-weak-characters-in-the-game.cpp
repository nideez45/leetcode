bool comp(vector<int>&a,vector<int>&b){
    if(a[0] == b[0]){
        return a[1]<b[1];
    }
    return a[0]>b[0];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),comp);
        int ans = 0;
        int mx = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i][1]<mx) ans++;
            mx = max(mx,nums[i][1]);
        }
        return ans;
    }
};