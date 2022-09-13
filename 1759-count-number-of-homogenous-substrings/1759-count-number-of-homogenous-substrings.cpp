class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int mod = 1e9+7;
        int i=0;
        int n = s.size();
        while(i<n){
            char c = s[i];
            int cnt = 0;
            while(i<n && s[i] == c){
                i++;
                cnt++;
            }
            long long temp = cnt;
            temp*=(cnt+1);
            temp/=2;
            temp%=mod;
            ans+=temp;
            ans%=mod;
        }
        return ans;
    }
};