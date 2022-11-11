class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        // contribution from each index
        int ans = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-i;
            left *= right;
            ans+= (left/2 + left%2)*arr[i];
        }
        return ans;
    }
};