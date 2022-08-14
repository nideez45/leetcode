class Solution {
public:
    
    vector<int> g[100000];
    unordered_map<string,int> mp;
    
    const int inf = 1e9;
    int dist[100000];
    int n;
    bool check(string &s,string &t){
        int cnt = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] != t[i])cnt++;
            if(cnt>1) return false;
        }
        return cnt == 1;
    }
    
    void bfs(){
        for(int i=0;i<=n+1;i++) dist[i] = inf;
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(int child:g[k]){
                if(dist[child]>1+dist[k]) {
                    dist[child] = 1+dist[k];
                    q.push(child);
                }
            }
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         n = wordList.size();
        for(int i=0;i<n;i++){
            mp[wordList[i]] = i+1;
        }
        // forming edges
        mp[beginWord] = 0;
        if(mp.find(endWord) == mp.end()) return 0;
       
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(wordList[i],wordList[j])){
                    g[mp[wordList[i]]].push_back(mp[wordList[j]]);
                    g[mp[wordList[j]]].push_back(mp[wordList[i]]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(check(beginWord,wordList[i])) {
                g[0].push_back(mp[wordList[i]]);
                g[mp[wordList[i]]].push_back(0);
            }
        }
    
        bfs();
        if(dist[mp[endWord]] == inf) return 0;
        return dist[mp[endWord]]+1;
    }
};