class Solution {
public:
    
    map<char,int> mp;
    int n;
    
    int rec(int level,int target){
        if(level == target){
            return 1;
        }
        int ans = 0;
        for(auto pr:mp){
            if(pr.second>=1){
                mp[pr.first]-=1;
                ans+=rec(level+1,target);
                mp[pr.first]+=1;
            }
        }
        return ans;
    }
    
    int numTilePossibilities(string tiles) {
        for(auto c:tiles){
            mp[c]++;
        }
        n = tiles.size();
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans+=rec(0,i);
        }
        return ans;
    }
};