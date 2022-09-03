class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        multiset<int> st;
        for(int i=0;i<k;i++) st.insert(0);
        vector <int> v(k+1,0);
        int n = rolls.size();
        for(int i=n-1;i>=0;i--){
            int mn = *(st.begin());
            int val = v[rolls[i]];
            st.erase(st.find(val));
            st.insert(mn+1);
            v[rolls[i]] = mn+1;
        }
        return *(st.begin())+1;
    }
};