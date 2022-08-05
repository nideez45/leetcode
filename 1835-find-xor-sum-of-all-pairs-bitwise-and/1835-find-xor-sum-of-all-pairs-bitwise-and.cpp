class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int cnt1[31] = {0};
        for(auto val:arr2){
            for(int i=0;i<31;i++){
                if((val&(1<<i))) cnt1[i]++;
            }
        }
        int cnt[31] = {0};
        for(auto val:arr1){
            for(int i=0;i<31;i++){
                if((val&(1<<i))){
                    cnt[i]+=cnt1[i];
                    cnt[i]%=2;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<31;i++){
            if(cnt[i]%2){
                ans+=(1<<i);
            }
        }
        return ans;
    }
};