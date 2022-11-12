class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int mod = 1e9+7;
        int n = strength.size();
        vector<int> next_smaller(n,n);
        vector<int> prev_smaller(n,-1);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({strength[i],i});
            }
            else{
                while(!st.empty() && st.top().first>=strength[i]) st.pop();
                if(st.size()){
                    prev_smaller[i] = st.top().second;
                }
                st.push({strength[i],i});
            }
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({strength[i],i});
            }
            else{
                while(!st.empty() && st.top().first>=strength[i]){
                    next_smaller[st.top().second] = i;
                    st.pop();
                }
                st.push({strength[i],i});
            }
        }
        // for(auto val:next_smaller) cout<<val<<" ";
        // cout<<'\n';
        // for(auto val:prev_smaller) cout<<val<<" ";
        long long pref[n];
        pref[0] = 1LL*strength[0]%mod;;
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + 1LL*strength[i];
            pref[i]%=mod;
        }
        long long ppref[n];
        ppref[0] = 1LL*pref[0]%mod;
        for(int i=1;i<n;i++){
            ppref[i] = ppref[i-1] + pref[i]%mod;
            ppref[i]%=mod;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int j = prev_smaller[i];
            int k = next_smaller[i];
           // cout<<j<<" "<<k<<'\n';
            long long term1 = 0;
            if(k-1>=0) {
                term1+= ppref[k-1];
                term1%=mod;
            }
            if(i-1>=0){
                term1 -= ppref[i-1];
                term1%=mod;
                if(term1<0) term1+=mod;
            }
            long long term2 = 0;
            if(i-1>=0) {
                term2+= ppref[i-1];
                term2%=mod;
            }
            if(j-1>=0){
                term2 -= ppref[j-1];
                term2%=mod;
                if(term2<0) term2+=mod;
            }
            term1*=(i-j);
            term1%=mod;
            term2*=(k-i);
            term1%=mod;
            long long term3 = term1-term2+mod;
            term3%=mod;
            if(term3<0) term3+=mod;
            term3*=1LL*strength[i];
            term3%=mod;
            ans+=term3;
            ans%=mod;
           // if(i == 1) cout<<term1<<" "<<term2<<" "<<term3<<'\n';
        }
        return ans;
    }
};