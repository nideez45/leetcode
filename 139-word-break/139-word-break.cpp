class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto w:wordDict){
            mp[w]++;
        }
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=20 && j<=i;j++){
                if(mp.find(s.substr(i-j,j)) != mp.end()) dp[i] = (dp[i] | dp[i-j]);
            }
        }
        return dp[n];
    }
};