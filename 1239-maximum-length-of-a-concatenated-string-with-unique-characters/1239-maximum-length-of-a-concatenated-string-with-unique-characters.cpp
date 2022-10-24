class Solution {
public:
    vector <string> a;
    string temp;
    int ans=0;
    int n;
    void rec(int level){
        if(level == n){
            ans = max(ans,(int)temp.size());
            return;
        }
        bool ok = true;
        int mask1=0;
        for(auto c: a[level]){
            if(mask1 & (1LL<<(c-'a'))) ok = false;
            mask1 ^= (1LL<<(c-'a'));
        }
        int mask2=0;
        for(auto c:temp) {
            mask2 ^= (1LL<<(c-'a'));
        }
        if(!(mask1&mask2) && ok){
            temp+=a[level];
            rec(level+1);
            for(int i=0;i<(int)a[level].size();i++) temp.pop_back();
        }
        
        
        rec(level+1);
        
    }
    
    int maxLength(vector<string>& arr) {
        a = arr;
        n = a.size();
        rec(0);
        return ans;
    }
};