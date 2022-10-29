class Solution {
public:
    
    // can do with no additional extra space ig
    
    const int mod = 1e9+7;
    
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int oc=0;
        int ec=1;
        int pref = 0;
        for(int i=0;i<n;i++){
            pref+=arr[i]%2;
            if((pref&1) == 0){
                ans += oc;
                ans%=mod;
                ec++;
            }
            else{
                ans+=ec;
                ans%=mod;
                oc++;
            }
        }
        return ans;
    }
};