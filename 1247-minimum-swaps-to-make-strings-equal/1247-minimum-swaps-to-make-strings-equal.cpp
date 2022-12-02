class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xc = 0;
        int yc = 0;
        if(s1.size() != s2.size()) return -1;
        for(auto c:s1) {
            if(c == 'x') xc++;
            else yc++;
        }
        for(auto c:s2){
            if(c == 'x') xc++;
            else yc++;
        }
        if(xc%2 || yc%2) return -1;
        int n = s1.size();
        int a = 0;
        int b = 0;
        for(int i=0;i<n;i++){
            if(s1[i] == 'x' && s2[i] == 'y') a++;
            if(s1[i] == 'y' && s2[i] == 'x') b++;
        }
        int ans = a/2 + b/2;
        if(a%2) ans+=2;
        return ans;
    }
};