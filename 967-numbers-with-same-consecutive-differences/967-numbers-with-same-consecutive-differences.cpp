class Solution {
public:
    
    vector<int> ans;
    int num=0;
    int n,k;
    
    void rec(int level,int prev){
        if(level == n){
            ans.push_back(num);
            return;
        }
        for(int i=0;i<10;i++){
            if(level == 0 && i == 0) continue;
            if(prev == -1){
                num = i;
                rec(level+1,i);
                num = 0;
            }
            else{
                if(abs(prev-i) != k) continue; 
                num*=10;
                num+=i;
                rec(level+1,i);
                num-=i;
                num/=10;
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int _n, int _k) {
        n = _n;
        k = _k;
        rec(0,-1);
        return ans;
    }
};