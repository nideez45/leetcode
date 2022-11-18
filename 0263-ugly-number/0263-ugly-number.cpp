class Solution {
public:
    
    int divide(int p,int n){
        if(n == 0) return 0;
        while(n%p == 0) n/=p;
        return n;
    }
    
    
    bool isUgly(int n) {
        n = divide(2,n);
        n = divide(3,n);
        n = divide(5,n);
        return n == 1;
    }
};