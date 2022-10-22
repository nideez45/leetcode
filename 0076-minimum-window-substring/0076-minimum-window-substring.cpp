class Solution {
public:
    
    map <char,int> mp1;
    map <char,int> mp2;
    int n,m;
    
    bool isValid(){
        bool ok = true;
        for(auto pr:mp2){
            char c = pr.first;
            if(mp1[c]<pr.second) ok = false;
        }
        return ok;
    }
    
    string minWindow(string s, string t) {
        n = s.size();
        m = t.size();
        if(n<m) return "";
        for(auto c:t) mp2[c]++;
        
        int l = -1;
        int r = n;
        int head = -1;
        int tail = 0;
        while(tail<n){
            while(head+1<n && !isValid()){
                head++;
                mp1[s[head]]++;
            }
            
            int temp = head-tail+1;
            //cout<<tail<<" "<<head<<'\n';
            
            if(temp<(r-l+1) && isValid()){
                l = tail;
                r = head;
            }
            if(head>=tail){
                mp1[s[tail]]--;
                tail++;
            }
            else{
                head = tail-1;
                tail++;
            }
        }
        if(l == -1 && r == n) return "";
        return s.substr(l,r-l+1);
    }
};