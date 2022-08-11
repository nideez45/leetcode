class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        for(auto c:s){
            freq1[c-'a']++;
        }
        for(auto c:t){
            freq2[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }
};