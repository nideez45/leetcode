class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int i=0;
        int j=n-1;
        int score = 0;
        while(i<=j){
            bool ok = false;
            while(i<=j && power>=tokens[i]){
                power-=tokens[i];
                i++;
                ok = true;
                score++;
            }
            if(i<j && score && ok==false){
                ok = true;
                power+=tokens[j];
                j--;
                score--;
            }
            if(ok == false) break;
        }
        return score;
    }
};