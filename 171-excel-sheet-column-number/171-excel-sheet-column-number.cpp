class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        reverse(columnTitle.begin(),columnTitle.end());
        long long pow = 1;
        for(auto c:columnTitle){
            ans+=((c-'A'+1)*pow);
            pow*=1LL*26;
        }
        return ans;
    }
};