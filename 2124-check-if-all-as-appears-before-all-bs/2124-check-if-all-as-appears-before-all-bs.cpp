class Solution {
public:
    // check if last a is before first b
    bool checkString(string s) {
        int n = s.size();
        int a = -1;
        int b = n;
        for(int i=0;i<n;i++){
            if(s[i] == 'a') a = i;
        }
        for(int i=0;i<n;i++){
            if(s[i] == 'b'){
                b = i;
                break;
            }
        }
        return a<b;
    }
};