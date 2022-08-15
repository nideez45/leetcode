class Solution {
public:
    
    // maximize the minimum
    // binary search on answer 
    
    bool check(int diff,vector<int>&position,int m){
        int cnt = 1;
        int prev = position[0];
        int i=1;
        int n = position.size();
        while(i<n){
            if(position[i]-prev<diff) i++;
            else{
                cnt++;
                prev = position[i];
                i++;
            }
        }
        return cnt>=m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int lo = 1;
        int hi = 1e9+5;
        int ans;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid,position,m)){
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }
        return ans;
    }
};