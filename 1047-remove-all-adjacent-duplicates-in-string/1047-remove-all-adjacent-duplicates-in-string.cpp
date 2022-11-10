class Solution {
public:
    
    // straight forward application of stack
    
    string removeDuplicates(string s) {
        string ans;
        stack<char> st;
        for(auto c:s){
            if(st.empty()){
                st.push(c);
            }
            else{
                if(st.top() == c) st.pop();
                else{
                    st.push(c);
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};