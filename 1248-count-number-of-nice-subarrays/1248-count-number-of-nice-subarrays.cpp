class Solution {
public:
    
    // a[i] = a[i]%2
    // the answer is number of subarray whose sum is k
    // can be done with number of subarrays whose sum is atmostk - sum atmost(k-1) ?
    // or the standard prefix sum way
    // prefj-prefi = k
    // 
    
    int atmostk(vector<int>&nums,int k){
        int sm = 0;
        int cnt = 0;
        int head = -1;
        int tail = 0;
        int n = nums.size();
        while(tail<n){
            while(head+1<n && (sm<k || nums[head+1]%2 == 0)){
                head++;
                if(nums[head]%2 == 1) sm++;
            }
            cnt += (head-tail+1);
            if(head>=tail){
                if(nums[tail]%2) sm--;
                tail++;
            }else{
                tail++;
                head = tail-1;
            }
        }
        return cnt;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums,k) - atmostk(nums,k-1);
    }
};