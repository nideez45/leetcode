class Solution {
public:
    
    // a[i] = a[i]%2
    // the answer is number of subarray whose sum is k
    // can be done with number of subarrays whose sum is atmostk - sum atmost(k-1) ?
    // or the standard prefix sum way
    // prefj-prefi = k
    // 
     
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;
        int pref = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            pref += nums[i]%2;
            if(mp.find(pref-k) != mp.end()){
                ans+=mp[pref-k];
            }
            mp[pref]++;
        }
        return ans;
    }
};