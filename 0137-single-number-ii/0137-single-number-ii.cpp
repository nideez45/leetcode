class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        for(int i=0;i<=31;i++)
        {
            int cnt = 0;
            for(auto x:nums)
            {
                int y = x;
                if((y>>i)&1) cnt++;
            }
            if(cnt%3!=0){
                ans = (ans|(1LL<<i));
            }
        }
        return ans;
    }
};