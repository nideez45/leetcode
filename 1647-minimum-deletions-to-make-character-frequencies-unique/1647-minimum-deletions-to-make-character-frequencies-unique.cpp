class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        int n = s.size();
        for(auto c:s) freq[c-'a']++;
        int cnt[n+1];
        for(int i=0;i<=n;i++) cnt[i] = 0;
        for(int i=0;i<26;i++){
            if(freq[i])cnt[freq[i]]++;
        }
        //for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
        int ans = 0;
        for(int i=n;i>=1;i--){
            if(cnt[i]>1){
                int temp = cnt[i]-1;
                ans+=cnt[i]-1;
                cnt[i-1]+=temp;
            }
        }
        
        return ans;
    }
};
