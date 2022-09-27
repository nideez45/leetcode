class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        set<int> st;
        int n = arr.size();
        for(int i=0;i<=n;i++) st.insert(i);
        int ans = 0;
        for(int i=0;i<n;i++){
            st.erase(arr[i]);
            if(*st.begin() == i+1) ans++;
        }
        return ans;
    }
};