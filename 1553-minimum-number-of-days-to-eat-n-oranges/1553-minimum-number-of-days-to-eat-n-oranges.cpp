class Solution {
public:
    map<int,int> dp;
    // dp[i] = minimum number of days to eat when i oranges are present
    
    int rec(int n){
        
        if(n == 0 || n ==1) return n;
        
        if(dp.find(n) != dp.end()) return dp[n];
        int ans;
        if(n%2!=0 && n%3!=0){
            ans = 1+rec(n-1);
        }
        if(n%2 == 0 && n%3 == 0){
            ans = 1+min({rec(n/2),rec(n/3)});
        }
        else if(n%2 == 0){
            ans = 1+min(rec(n-1),rec(n/2));   
        }
        else if(n%3 == 0){
            ans = 1+min(rec(n-1),rec(n/3));   
        }
        return dp[n] = ans;
    }
    
    int minDays(int n) {
        return rec(n);   
    }
};