class Solution {
public:
    
    // standard problem of number of subarrays with given target sum
    int func(vector<int> a,int target){
        map<int,int> mp;
        int pref = 0;
        mp[0]=1;
        int cnt=0;
        int n = a.size();
        for(int i=0;i<n;i++){
            pref+=a[i];
            // prefj-prefi = target
            // for current prefj looking for prefixes with sum of prefj-target
            if(mp.find(pref-target) != mp.end()) cnt+=mp[pref-target];
            mp[pref]++;
        }
        return cnt;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int row1 = 0;row1<n;row1++){
            vector<int> psum(m,0);
            for(int row2=row1;row2<n;row2++){
                for(int i=0;i<m;i++)psum[i]+=matrix[row2][i];
                ans+=func(psum,target);
            }
        }
        return ans;
    }
};