class Solution {
public:
    
    bool check(int a,int b,int c){
        return a+b>c && a+c>b && b+c>a;
    }
    
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<=n-3;i++){
            if(check(nums[i],nums[i+1],nums[i+2])){
                ans = nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return ans;
    }
};