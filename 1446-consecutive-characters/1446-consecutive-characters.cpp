class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        int i=0;
        int n= s.size();
        while(i<n){
            char c = s[i];
            int cnt = 0;
            while(i<n && c == s[i]){
                i++;
                cnt++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};