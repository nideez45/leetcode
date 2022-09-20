class Solution {
public:
    
    map<int,int> dp;
    
    int rec(long long n){
        if(n ==1){
            return 0;
        }
        if(dp.find(n) != dp.end()) return dp[n];
        int ans = 0;
        if(n%2==0){
            ans = 1+rec(n/2);
        }
        else{
            ans = 1+min(rec(n-1),rec(n+1));
        }
        return dp[n] = ans;
    }
    
    int integerReplacement(int n) {
        return rec(n);
    }
};