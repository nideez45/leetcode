class Solution {
public:
    
    // length longest common subarray - O(N^2) with dp
    
    int dp[1001][1001];
    vector<int> nums1;
    vector<int> nums2;
    int n,m;
    
    int rec(int level1,int level2){
        if(level1 == n || level2 == m){
            return 0;
        }
        if(dp[level1][level2] != -1){
            return dp[level1][level2];
        }
        int ans;
        if(nums1[level1] != nums2[level2]) ans = 0;
        else{
            ans = 1+rec(level1+1,level2+1);
        }
        return dp[level1][level2] = ans;
    }
    
    int findLength(vector<int>& _nums1, vector<int>& _nums2) {
        nums1 = _nums1;
        nums2 = _nums2;
        n = nums1.size();
        m = nums2.size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,rec(i,j));
            }
        }
        return ans;
    }
};