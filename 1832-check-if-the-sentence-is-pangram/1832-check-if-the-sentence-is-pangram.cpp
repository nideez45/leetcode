class Solution {
public:
    bool checkIfPangram(string sentence) {
        int freq[26] = {0};
        for(auto c:sentence) freq[c-'a']++;
        bool ok = true;
        for(int i=0;i<26;i++){
            if(freq[i] == 0) ok = false;
        }
        return ok;
    }
};