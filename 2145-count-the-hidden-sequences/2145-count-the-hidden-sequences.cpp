class Solution {
public:
    
    /*
    every sequence is fixed with taking first element
    need to check for every element in lower-higher, if the sequence is possible
    a1 a2 a3 a4
    d1 d2 d3      a1 = a1
    a2 = a1+d1    a2 = a1+d1 
    a3 = a2+d2 -> a3 = a1+d1+d2
    a4 = a3+d3 -> a4 = a1+d1+d2+d3
    
    need to find smallest and largest sum of d1+....+di
    and check if a1+smallest is more than equal to lower
    and check if a1+largest is less than eqaul to upper
        
    */
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long mx = -1e11;
        long mn = 1e11;
        long sm = 0;
        for(auto val:differences){
            sm+=1LL*val;
            mn = min(mn,sm);
            mx = max(mx,sm);
        }
        int ans = 0;
        for(int choice = lower;choice<=upper;choice++){
            if( (1LL*choice+mx <= 1LL*upper) && (1LL*choice+mn >= 1LL*lower) ) ans++;
        }
        return ans;
    }
};