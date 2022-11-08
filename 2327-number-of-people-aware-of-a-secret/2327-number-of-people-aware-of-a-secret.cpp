class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9+7;
        int know_at[2005] = {0};
        know_at[1] = 1;
        for(int i=1;i<=n;i++){
            for(int j=i+delay;j<i+forget;j++){
                know_at[j] = (know_at[j]+know_at[i])%mod;
            }
        }
        int ans = 0;
        int i=0;
        int j=n;
        while(i<forget){
            ans+=know_at[j];
            ans%=mod;
            j--;
            i++;
        }
        return ans;
    }
};