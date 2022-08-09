class Solution {
public:
    
    // dp[i] = number of binary trees with i as root
    const int mod = 1e9+7;
    
    // to store for each number, {a,b} such that axb = number
    map<int,vector<pair<int,int>>> mp;
    
    // to map values to index
    map<long long,int> idx;
    int n;
    
    int dp[1001];
    
    int rec(int val){
        // base case, if it cant be further extended
        if(mp[val].size() == 0){
            return 1;
        }
        if(dp[idx[val]] != -1){
            return dp[idx[val]];
        }
        // dont have any left or right child
        int ans = 1;
        for(auto pr:mp[val]){
            long long ans1 = rec(pr.first);
            long long ans2 = rec(pr.second);
            ans1*=ans2;
            ans1%=mod;
            
            // swap left and right
            if(pr.first!=pr.second)ans1*=2LL;
            ans1%=mod;
            ans+=ans1;
            ans%=mod;
        }
        return dp[idx[val]] = ans;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        n = arr.size();
        for(int i=0;i<n;i++) idx[arr[i]] = i;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long x = 1LL*arr[i]*arr[j];
                if(idx.find(x) != idx.end()){
                    mp[x].push_back({arr[i],arr[j]});
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=rec(arr[i]);
            ans%=mod;
        }
      //  for(int i=0;i<n;i++) cout<<rec(arr[i])<<" ";
        return ans;
    }
};