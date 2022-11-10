class Solution {
public:
    
    // number of set bits in a|b + number of set bits in a&b = number of sets bits in a + number of set bits in b
    
    int bc(int num){
        int cnt = 0;
        for(int i=0;i<31;i++){
            if((num&(1<<i))) cnt++;
        }
        return cnt;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int>st;
        for(auto &val:nums) st.insert(val);
        vector<int> v;
        for(auto &val:st) v.push_back(val);
        vector<int> x;
        for(auto &val:v){
            x.push_back(bc(val));
        }
        sort(x.begin(),x.end());
        long long ans = 0;
        int n = x.size();
        for(int i=0;i<n;i++){
            auto it = x.begin()+i+1;
            int idx = lower_bound(it,x.end(),k-x[i])-x.begin();
            if(idx>=i){
                ans+= 1LL*(n-idx);
            }
        }
        ans*=2LL;
        // handles the cases where same element forms pair
        for(auto &val:x){
            if(2*val>=k) ans++;
        }
        
        return ans;
    }
};