class Solution {
public:
    
    // dp1 -> length of longest decreasing subarray ending at i, (left to right)
    // dp2 = length of longest decreasing subarray ending at i ,(right to left)
    
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            v[i] = security[i-1];
        }
        int dp1[n+1];
        int dp2[n+1];
        for(int i=1;i<=n;i++) dp1[i] = dp2[i] = 1;
        for(int i=2;i<=n;i++){
            if(v[i]<=v[i-1]) dp1[i] = 1+dp1[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(v[i]<=v[i+1]) dp2[i] = 1+dp2[i+1];
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(i+time>n || i-time<1) continue;
            if(dp1[i]>=1+time && dp2[i]>=1+time) ans.push_back(i-1);
        }
        return ans;
    }
};