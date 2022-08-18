class Solution {
public:
    
    long long atmost(int k,string s){
        int n = s.size();
        long long cnt = 0;
        int head = -1;
        int tail = 0;
        int dist = 0;
        int freq[26] = {0};
        while(tail<n){
            while(head+1<n && (dist<k || freq[s[head+1]-'a'])){
                head++;
                if(freq[s[head]-'a'] == 0) dist++;
                freq[s[head]-'a']++;
            }
            cnt+=(1LL*head - 1LL*tail +1);
            if(head>=tail){
                freq[s[tail]-'a']--;
                if(freq[s[tail]-'a'] == 0) dist--;
                tail++;
            }
            else{
                tail++;
                head = tail-1;
            }
        }
        return cnt;
    }
    
    long long appealSum(string s) {
        long long ans = 0;
        for(int k=1;k<=26;k++){
            ans+= k*(atmost(k,s)-atmost(k-1,s));
           
        }
        return ans;
    }
};