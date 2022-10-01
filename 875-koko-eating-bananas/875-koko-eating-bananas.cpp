class Solution {
public:
    
   
    // piles[i] -> number of bananas in ith pile
    // h - is the time before which we have to finish
    // eating all the bananas
    // find k -> minimum banana per hour to finish
    // eating all the bananas
    // 0 1 2 3 4 5 6 7 8 9
    // 0 0 0 0 0 0 1 1 1 1 1


    // piles =  11 15 6 7 , h = 6 , mid = 4 
    bool check(int mid,vector<int>piles,int h){
        int time = 0; // time taken when banana per hour
        // speed is mid
        for(int i=0;i<piles.size();i++){
            time += (piles[i]/mid);
            if(time>h) return false;
            if(piles[i]%mid) time++;
        }
        return time<=h;
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