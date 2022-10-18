class Solution {
public:
    
    string rec(int n){
        if(n == 1){
            return "1";
        }
        string temp = rec(n-1);
        string ans;
        int i=0;
        int sz = temp.size();
        while(i<sz){
            char c = temp[i];
            int cnt = 0;
            while(i<sz && temp[i] == c){
                cnt++;
                i++;
            }
            for(auto x:to_string(cnt)) ans.push_back(x);
            ans.push_back(c);
        }
        return ans;
    }
    
    string countAndSay(int n) {
       return rec(n); 
    }
};