class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        int idx1;
        int idx2;
        for(int i=0;i<n;i++){
            if(nums[i] == mx){
                idx2 = i;
            }
            if(nums[i] == mn){
                idx1 = i;
            }
        }
        if(idx1>idx2) swap(idx1,idx2);
        idx1++;
        idx2++;
        idx2 = n-idx2+1;
        //ut<<idx1<<" "<<idx2<<'\n';
        int ans = n+1;
        ans = min(ans,idx1+idx2);
        ans = min(ans,n-idx2+1);
        ans = min(ans,n-idx1+1);
        return ans;
    }
};