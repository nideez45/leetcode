class Solution {
public:
    
    void merge(int l,int mid,int r,vector<int>&nums){
        // l to mid
        // mid+1 to r
        
        vector<int> temp(r-l+1);
        int L = l; // 2
        int R = mid+1; // 3
        int n = mid+1; // 3
        int m = r+1; // 4
        int k=0;
    
        while(L<n && R<m){
            if(nums[L]<nums[R]){
                temp[k] = nums[L];
                k++;
                L++;
            }
            else{
                temp[k] = nums[R];
                k++;
                R++;
            }
        }
    
        while(L<n){
            temp[k] = nums[L];
            L++;
            k++;
        }
        while(R<m){
            temp[k] = nums[R];
            R++;
            k++;
        }
        for(int i=l;i<=r;i++){
            nums[i] = temp[i-l];
        }
        
    }
    
    void mergesort(int l,int r,vector<int>&nums){
        if(l<r){
            int mid = (l+r)/2;
            mergesort(l,mid,nums);
            mergesort(mid+1,r,nums);
            merge(l,mid,r,nums);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(0,n-1,nums);
        
        return nums;
    }
};