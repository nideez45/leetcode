class Solution {
public:
    
    const int mod = 1e9+7;

    int concatenatedBinary(int n) {
        int pos = 0;
        int ans = 0;
        int pow2 = 1;
        for(int i=n;i>=1;i--){
            int j=0;
            while((1<<j)<=i){
                if(((1<<j)&i)){
                    ans+=pow2;
                    ans%=mod;
                   
                }
                pow2*=2LL;
                pow2%=mod;
                pos++;
                j++;
            }
        }
        
        return ans;
    }
};