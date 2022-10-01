class Solution {
public:
    
    bool check(int mid,vector<int>&piles,int h){
        int cnt = 0; // to store the number of hours needed
        int n = piles.size();
        for(int i=0;i<n;i++){
            cnt+= (piles[i]/mid);
            if(cnt>h) return false;
            if(piles[i]%mid) cnt++;
        }
        return cnt<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 1e9+5;
        int ans;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid,piles,h)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};