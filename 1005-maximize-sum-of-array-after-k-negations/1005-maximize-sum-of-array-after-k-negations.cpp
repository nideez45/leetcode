class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto val:nums) pq.push(val);
        while(k){
            int x = pq.top();
            x = -x;
            pq.pop();
            pq.push(x);
            k--;
        }
        int ans = 0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};