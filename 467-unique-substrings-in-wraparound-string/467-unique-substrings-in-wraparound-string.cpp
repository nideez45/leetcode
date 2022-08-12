class Solution {
public:
    
    bool check(char a,char b){
        // need to check if a follows b
        if(b == '$') return 1;
        if(a-b == 1) return 1;
        if(b == 'z' && a == 'a') return 1;
        return 0;
    }
    
    
    int findSubstringInWraproundString(string p) {
        int len[26] = {0};
        // from each character the maximum length counted till now
        int ans = 0;
        int n = p.size();
        int head = -1;
        int tail = 0;
        char prev = '$';
        while(tail<n){
            while(head+1<n && check(p[head+1],prev)){
                head++;
                prev = p[head];
            }
            // starting char is p[tail]
            int cur = head-tail+1;
            if(len[p[tail]-'a']<cur){
                ans+=cur-len[p[tail]-'a'];
                len[p[tail]-'a'] = cur;
            }
            if(head>tail){
                tail++;
            }
            else{
                tail++;
                head = tail-1;
                prev = '$';
            }
        }
        return ans;
    }
};