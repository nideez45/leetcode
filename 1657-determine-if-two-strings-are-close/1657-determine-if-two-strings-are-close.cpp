class Solution {
public:
    
    
    bool closeStrings(string word1, string word2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        for(auto c:word1) freq1[c-'a']++;
        for(auto c:word2) freq2[c-'a']++;
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<26;i++){
            if((freq1[i] && !freq2[i] ) || (!freq1[i] && freq2[i]) ) return false;
            if(freq1[i]) v1.push_back(freq1[i]);
            if(freq2[i]) v2.push_back(freq2[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};