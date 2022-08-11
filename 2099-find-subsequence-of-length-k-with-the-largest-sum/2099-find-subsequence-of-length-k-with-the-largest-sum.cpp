class Solution {
public:
    
    // Time - O(nlogk)
    // first getting the largest k elements, then sorting their indices to get subseq
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k) pq.pop();
        }
        vector<int> idx;
        while(!pq.empty()){
            auto pr = pq.top();
            pq.pop();
            idx.push_back(pr.second);
        }
        sort(idx.begin(),idx.end());
        vector<int> ans;
        for(int i=0;i<k;i++) ans.push_back(nums[idx[i]]);
        return ans;
    }
};