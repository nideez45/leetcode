class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({nums[i],0});
            }
            else{
                int ops = 0;
                while(!st.empty() && st.top().first<nums[i]){
                    if(st.top().second>ops){
                        ops= st.top().second;
                    }
                    else{
                        ops+=1;
                    }
                    st.pop();
                }
                st.push({nums[i],ops});
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans = max(ans,st.top().second);
            st.pop();
        }
        return ans;
    }
};