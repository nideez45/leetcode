class Solution {
public:
    
    /*
    two pointer approach - O(N)
    from each index try to go till the index where sum >= target
    now on increasing the start index the end index can only stay there or move forward
    because all elements are positive
    
    binary search from each index - O(NlogN)
    
    */
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int head = -1;
        int tail = 0;
        int ans = 1e9;
        int sum = 0; // maintain the running sum
        while(tail<n){
            while(head+1<n && sum+nums[head+1]<target){
                head++;
                sum+=nums[head];
            }
            // now tail to head+1 is a valid range
            
            if(head!=n-1 && sum+nums[head+1]>=target)ans = min(ans,head-tail+2);
            if(tail<=head){
                sum-=nums[tail];
                tail++;
            }
            else{
                tail++;
                head = tail-1;
            }
        }
        if(ans == 1e9) ans = 0;
        return ans;
    }
};