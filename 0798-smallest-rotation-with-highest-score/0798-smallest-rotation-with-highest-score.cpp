class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        int rot[n+1];
        for(int i=0;i<n+1;i++) rot[i] = 0;
        for(int i=0;i<n;i++){
            int val = nums[i];
            // need to find the rotations in which current values index is from val to n-1
            int st = (i+1);
            int diff = n - val ;
            int en = min(n-1,st+diff-1);
            // need to increment from start to end 
            rot[st]+=1;
            rot[en+1]-=1;
           // cout<<st<<" "<<en<<'\n';
            if(val <= i){
                int diff = i-val;
                // need to increment from 0 to diff-1
                rot[0]+=1;
                rot[diff+1]-=1;
            }
        }
        for(int i=1;i<=n;i++) rot[i]+=rot[i-1];
        int mx = 0;
        int idx = 0;
        for(int i=0;i<n;i++){
            if(rot[i]>mx){
                mx = rot[i];
                idx = i;
            }
        }
        //for(int i=0;i<n;i++) cout<<rot[i]<<" ";
        return idx;
    }
};