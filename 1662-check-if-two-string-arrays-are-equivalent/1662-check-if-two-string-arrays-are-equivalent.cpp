class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0;
        int j=0;
        int p1=0;
        int p2=0;
        int n = word1.size();
        int m = word2.size();
        
        while(i<n && j<m){
            while(p1<word1[i].size() && p2<word2[j].size()){
                if(word1[i][p1] != word2[j][p2]) {
                    return false;
                }
                else{
                    p1++;
                    p2++;
                }
            }
            if(p1 == word1[i].size()) {
                p1 = 0;
                i++;
            }
            if(p2 == word2[j].size()){
                p2 = 0;
                j++;
            }
        }
        if(p1!=0 || p2!=0 || i!=n || j!=m) return false;
        return true;
    }
};