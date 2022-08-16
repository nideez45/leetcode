class Solution {
public:
    
    
    bool check(int mx,vector<int>&quantities,int n){
        int cnt = 0;
        for(int i=0;i<quantities.size();i++){
                cnt += quantities[i]/mx;
                if(quantities[i]%mx) cnt++;
            }
        
        return cnt<=n;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1;
        int hi = *max_element(quantities.begin(),quantities.end());
        int ans=-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid,quantities,n)){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }
        return ans;
    }
};