class Solution {
public:

    
    int func(vector<int> a,int target){
        multiset<int> st;
        int pref = 0;
        st.insert(0);
        int best = -1e9;
        int n = a.size();
        for(int i=0;i<n;i++){
            pref+=a[i];
            // prefj-prefi <= target
            // for current prefj looking for prefixes with sum >= prefj-target
            
            auto it = st.lower_bound(pref-target);
            if(it != st.end()){
                best = max(best,pref-*it);
            }
            
            st.insert(pref);
        }
        return best;
    }
    
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -1e9;
        for(int row1 = 0;row1<n;row1++){
            vector<int> psum(m,0);
            for(int row2=row1;row2<n;row2++){
                for(int i=0;i<m;i++)psum[i]+=matrix[row2][i];
                ans=max(ans,func(psum,k));
            }
        }
        return ans;
    }
};