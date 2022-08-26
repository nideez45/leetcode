class Solution {
public:
    
    vector<int> digits(int n){
        vector<int> f(10,0);
        string a = to_string(n);
        for(auto c:a) f[c-'0']++;
        return f;
    }
    
    bool reorderedPowerOf2(int n) {
        bool ok = false;
        int p2 = 1;
        vector<int> f1 = digits(n);
        while(p2<=1e9+5){
            vector<int> f2 = digits(p2);
            if(f1 == f2) ok = true;
            p2*=2;
        }
        return ok;
    }
};