class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++){
            if(!a[i]) a[i]=-1;
        }
        int ans = 0;
        map<int,int> mp;
        int psum = 0;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            psum+=a[i];
            if(mp.find(psum) != mp.end()){
                ans = max(ans,i-mp[psum]);
            }
            else{
                mp[psum] = i;
            }
        }
       return ans;
    }
};