class Solution {
public:
    
    // restructure the code
    // after i==j just need to merge both st1 and st2, take smallest k out of it
    // took 30mins - bad
    // didnt think of overlapping condition first
    long long totalCost(vector<int>& costs, int k, int candidates) {
        multiset<int> st1;
        multiset<int> st2;
        int n = costs.size();
        if(n/2+n%2<=candidates){
            long long ans = 0;
            for(auto val:costs) st1.insert(val);
            while(k){
                ans+=1LL*( *(st1.begin()));
                st1.erase(st1.begin());
                k--;
            }
            return ans;
        }
        
        for(int i=0;i<candidates;i++) st1.insert(costs[i]);
        for(int i=n-1;i>=n-candidates;i--) st2.insert(costs[i]);
        
        int i = candidates;
        int j = n-candidates-1;
        long long ans = 0;
      
        while(i<=j && k){
            if(*(st1.begin())>*(st2.begin())){
                ans+= 1LL*(*(st2.begin()));
                // /cout<<"here1"<<'\n';
                st2.erase(st2.begin());
                st2.insert(costs[j]);
                j--;
            }
            else{
                ans+= 1LL*(*(st1.begin()));
                //cout<<"here2"<<'\n';
                st1.erase(st1.begin());
                st1.insert(costs[i]);
                i++;
            }
            k--;
        }
        if(i==j) st2.insert(costs[i]);
        // for(auto val:st1) cout<<val<<" ";
        // cout<<'\n';
        // for(auto val:st2) cout<<val<<" ";
        // cout<<'\n';
        while(k){
            if(st1.size() && st2.size()){
                if(*(st1.begin()) > *(st2.begin())){
                    ans+= 1LL*(*(st2.begin()));
                    st2.erase(st2.begin());
                }
                else{
                     ans+= 1LL*(*(st1.begin()));
                    st1.erase(st1.begin());
                }
            }
            else if(st1.size()){
                 ans+= 1LL*(*(st1.begin()));
                    st1.erase(st1.begin());
            }
            else{
                 ans+= 1LL*(*(st2.begin()));
                    st2.erase(st2.begin());
            }
            k--;
        }
        return ans;
    }
};