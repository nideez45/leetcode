class Solution {
public:
    vector<int> g[505];
    unordered_map<string,int> mp;
    unordered_map<int,string> mp1;
    const int inf = 1e9;
    int dist[505];
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
    
    //back tracking
    vector<string> temp;
    vector<vector<string>> ans;
    string bw;
    
    void rec(string &word,int dep){
        if(dep == 0){
            temp.push_back(bw);
            vector<string> temp1 = temp;
            reverse(temp1.begin(),temp1.end());
            ans.push_back(temp1);
            temp.pop_back();
            return;
        }
        temp.push_back(word);
        for(int child:g[mp[word]]){
            if(dist[child] == dep-1){
                rec(mp1[child],dep-1);
            } 
        }
        temp.pop_back();
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         n = wordList.size();
        bw = beginWord;
        for(int i=0;i<n;i++){
            mp[wordList[i]] = i+1;
            mp1[i+1] = wordList[i];
        }
        // forming edges
        mp[beginWord] = 0;
        mp1[0] = beginWord;
        if(mp.find(endWord) == mp.end()) return ans;
       
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(wordList[i] == beginWord || wordList[j] == beginWord) continue;
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
        rec(endWord,dist[mp[endWord]]);
        return ans;
    }
};