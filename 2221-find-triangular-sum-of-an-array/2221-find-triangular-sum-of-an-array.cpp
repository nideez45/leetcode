class Solution {
public:
    
    // getting contribution from each index
    // to reach the bottom most element number of steps taken = n-1
    // index i can take i-1 left
    // so number of different ways = (n-1) C (i-1) from each index
    // take sum of this with mod 10
    
    int ncr[1001][1001];
    
    void computencr(){
        ncr[0][0] = 1;
        for(int i=1;i<=1000;i++){
            for(int j=0;j<=i;j++){
                if(j == 0) ncr[i][j] = 1;
                else ncr[i][j] = (ncr[i-1][j-1]+ncr[i-1][j])%10;
            }
        }
    }
    
    int triangularSum(vector<int>& nums) {
        computencr();
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ans+=(nums[i]*ncr[n-1][i])%10;
            ans%=10;
        }
        return ans;
    }
};