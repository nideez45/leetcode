class Solution {
public:
    // dp[i] = length of longest increasing subsequence ending at value i
    // need some efficient way to get max of range
    // segment tree
    
    int dp[100005];
    int t[4*100005];
    
    int query(int idx,int l,int r,int lq,int rq){
        if(l>rq || r<lq) return 0;
        if( lq <=l && r<=rq) return t[idx];
        int mid = (l+r)/2;
        return max(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq));
    }
    
    void update(int idx,int l,int r,int pos,int val){
        if(l>pos || pos>r) return;
        if(l == r){
            dp[pos] = val;
            t[idx] = val;
            return;
        }
        int mid = (l+r)/2;
        update(2*idx,l,mid,pos,val);
        update(2*idx+1,mid+1,r,pos,val);
        t[idx] = max(t[2*idx],t[2*idx+1]);
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int prev = max(0,nums[i]-k);
            update(1,0,100004,nums[i],max(dp[nums[i]],1+query(1,0,100004,prev,nums[i]-1)));
           // cout<<dp[nums[i]]<<" ";
        }
        return *max_element(dp,dp+100005);
    }
};