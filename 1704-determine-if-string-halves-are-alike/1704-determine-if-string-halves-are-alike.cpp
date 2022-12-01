class Solution {
public:
    
    int count(string s){
        int cnt = 0;
        for(auto c:s){
            if(c<=90) c+=32;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' ||c == 'u') cnt++;
        }
        return cnt;
    }
    
    bool halvesAreAlike(string s) {
        return count(s.substr(0,s.size()/2)) == count(s.substr(s.size()/2));
    }
};