class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        int n = deck.size();
        for(int i=0;i<n;i++) dq.push_back(i);
        sort(deck.begin(),deck.end());
        int current = 0;
        vector<int> ans(n);
        while(!dq.empty()){
            int k = dq.front();
            ans[k] = current;
            dq.pop_front();
            if(!dq.empty()){
                int val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
            current++;
        }
        vector<int> ans1(n);
        for(int i=0;i<n;i++){
            ans1[i] = deck[ans[i]];
        }
        return ans1;
    }
};