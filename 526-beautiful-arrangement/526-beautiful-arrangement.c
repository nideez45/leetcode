
int cnt[16];
int ans;
int n;
void rec(int level){
    if(level == n){
        ans++;
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(cnt[i]){
            int idx = level+1;
            if(idx%i == 0 || i%idx == 0){
                cnt[i]--;
                rec(level+1);
                cnt[i]++;
            }
        }
    }
}

int countArrangement(int _n){
    n = _n;
    ans = 0;
    for(int i=1;i<=n;i++) cnt[i] = 1;
    rec(0);
    return ans;
}