class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        else{
        int left[n];
        int right[n];
        int left_max = 0;
        for(int i=0;i<n;i++){
            if(height[i]>left_max) left_max = height[i];
            left[i] = left_max;
        }
        int right_max = 0;
        for(int i=n-1;i>=0;i--){
            if(height[i]>right_max) right_max = height[i];
            right[i] = right_max;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
        }
    }
};