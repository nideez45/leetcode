class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = -1;
        map<char,int> mp;
        int ans = 0;
        while(l<n){
            while(r+1<n && mp.find(s[r+1]) == mp.end()){
                r++;
                mp[s[r]]++;
            }
            // tail ... head
            ans = max(ans,r-l+1);
            mp.erase(s[l]);
            l++;
        }
        return ans;
    }
};