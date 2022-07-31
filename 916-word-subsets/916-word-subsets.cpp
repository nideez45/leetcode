class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq[26];
        for(int i=0;i<26;i++) freq[i] = 0;
        
        // find freq of each char so that the freq array satisfies every word in words2
        for(auto word:words2){
            int temp[26];
            for(int i=0;i<26;i++) temp[i] = 0;
            for(auto c:word) temp[c-'a']++;
            for(int i=0;i<26;i++){
                freq[i] = max(freq[i],temp[i]);
            }
        }
        vector<string> ans;
        
        // find strings in words1 whose freq of char is more that or equal to required
        for(auto word:words1){
            bool ok = true;
            int temp[26];
            for(int i=0;i<26;i++) temp[i] = 0;
            for(auto c:word) temp[c-'a']++;
            for(int i=0;i<26;i++){
                if(freq[i]>temp[i]) ok = false;
            }
            if(ok) ans.push_back(word);
        }
        return ans;
    }
};