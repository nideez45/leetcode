class Solution {
public:
    
    //  x c c c c x
    
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int i=0;
        int n = colors.size();
        while(i<n){
            char x = colors[i];
            int mx = 0;
            int total = 0;
            while(i<n && colors[i]==x){
                mx = max(mx,neededTime[i]);
                total+=neededTime[i];
                i++;
            }
            ans+=total-mx;
          //  cout<<ans<<" ";
        }
        return ans;
    }
};