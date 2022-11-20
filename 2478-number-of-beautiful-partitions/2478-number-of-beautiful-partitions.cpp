class Solution {
public:
    
    map<int,int>primes;
    string s;
    int n;
    int m;
    vector<int> v;
    
    // index,k left
    int mod = 1e9+7;
    int dp[1005][1005];
    
    int rec(int level,int left){
        if(level == n){
            return (left == 0);
        }
        if(left==0) return 0;
        if(dp[level][left] != -1) return dp[level][left];
        
        int ans = 0;
        int idx = lower_bound(v.begin(),v.end(),level)-v.begin();
        for(int i=idx;i<v.size();i++){
            // level to v[idx]
            if(v.size()-i<left) break;
            if(v[i]-level+1<m) continue;
            ans+=rec(v[i]+1,left-1);
            ans%=mod;
        }
        return dp[level][left] = ans;
    }
    
    int beautifulPartitions(string _s, int k, int minLength) {
        primes[2]++;
        primes[3]++;
        primes[5]++;
        primes[7]++;
        s = _s;
        n = s.size();
        m = minLength;
        if(primes.find(s[0]-'0') == primes.end() || primes.find(s[n-1]-'0') != primes.end()) return 0;
        for(int i=0;i<n-1;i++){
            if(primes.find(s[i]-'0') == primes.end()  && primes.find(s[i+1]-'0') != primes.end()){
                v.push_back(i);
            }
        }
        v.push_back(n-1);
        memset(dp,-1,sizeof(dp));
        return rec(0,k);
    }
};