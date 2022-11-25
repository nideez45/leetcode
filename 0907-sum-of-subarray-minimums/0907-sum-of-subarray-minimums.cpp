class Solution {
public:
    vector <int> Pse(vector <int> &a,int n){
        vector <int> pse(n,-2);
        stack <pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({a[i],i});
                pse[i]=-1;
            }
            else{
                while(!st.empty() && st.top().first>=a[i]){
                    st.pop();
                    
                }
                if(!st.empty()){
                    pse[i] = st.top().second;
                }
                else {
                    pse[i] = -1;
                }
                st.push({a[i],i});
            }
        }
        while(!st.empty()){
            int idx = st.top().second;
           if(pse[idx] == -2) pse[idx] = -1;
            st.pop();
        }
        
        return pse;
    }
    vector <int> Nse(vector <int> &a,int n){
         vector <int> nse(n,-2);
        stack <pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({a[i],i});
                nse[i] = n;
            }
            else{
                while(!st.empty() && st.top().first>a[i]){
                    st.pop();
                }
                if(!st.empty()){
                    nse[i] = st.top().second;
                }
                else nse[i] = n;
                st.push({a[i],i});
            }
        }
        while(!st.empty()){
            int idx = st.top().second;
           if(nse[idx] == -2) nse[idx] = n;
            st.pop();
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
         vector <int> nse(n);
        vector <int> pse(n);
        pse = Pse(a,n);
        nse = Nse(a,n);
        long long ans=0;
        int mod = 1000000007;
        for(int i=0;i<n;i++){
            long long temp1 = 1LL*(i-pse[i])*(nse[i]-i)*a[i];
            temp1%=mod;
            ans+=temp1;
            ans%=mod;
        }
        return ans;
    }
};