bool comp(vector<int>&a,vector<int>&b){
    if(a[1] == b[1]){
        return a[0]<b[0];
    }
    return a[1]<b[1];
}

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),comp);
        int cnt = 0;
        set <int> st;
        int n = events.size();
        for(int i=1;i<=100000;i++) st.insert(i);
        for(int i=0;i<n;i++){
            auto it = st.lower_bound(events[i][0]);
            if(it == st.end() || *it > events[i][1]) continue;
            else{
                cnt++;
                st.erase(it);
            }
        }
        return cnt;
    }
};