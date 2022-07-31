class Solution {
public:
    double angleClock(int h, int m) {
         double ans = 30.0*h+ m/2.0 -6.0*m;
        ans = abs(ans);
        if(ans>180) ans = 360-ans;
        return ans;
    }
};