class Solution {
public:
    
    // concept used - two pointers
    // from each start index go as far as you can , condition - atmost 2 distinct fruit types
    
    int totalFruit(vector<int>& fruits) {
        int freq[100005] = {0};
        int cnt = 0;
        int ans = 0;
        int head = -1;
        int tail = 0;
        int n = fruits.size();
        while(tail<n){
            while(head+1<n && (cnt<2 || freq[fruits[head+1]])){
                head++;
                if(freq[fruits[head]] == 0) cnt++;
                freq[fruits[head]]++;
            }
            if(cnt<=2) ans = max(ans,head-tail+1);
            if(head>=tail){
                freq[fruits[tail]]--;
                if(freq[fruits[tail]] == 0) cnt--;
                tail++;
            }
            else{
                tail++;
                head = tail-1;
            }
        }
        return ans;
    }
};