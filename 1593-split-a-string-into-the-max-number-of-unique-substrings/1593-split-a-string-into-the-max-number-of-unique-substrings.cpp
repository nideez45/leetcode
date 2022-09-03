class Solution {
public:
    
    map<string,int> mp;
    int ans = 0;
    int n;
    string s;
    
    void rec(int level){
        if(level == n){
            ans = max(ans,(int)mp.size());
            return;
        }
        string temp;
        for(int i=0;i<n;i++){
            if(level+i>=n) break;
            temp.push_back(s[level+i]);
            if(mp.find(temp) == mp.end()){
                mp[temp] = 1;
                rec(level+i+1);
                mp.erase(temp);
            }
        }
    }
    
    int maxUniqueSplit(string _s) {
        s = _s;
        n = s.size();
        rec(0);
        return ans;
    }
};