class Solution {
public:
    
    vector<string> generate(string s){
        vector<string> v;
        vector<char> gene = {'A','C','G','T'};
        for(int i=0;i<s.size();i++){
            for(auto c:gene){
                if(c!=s[i]){
                    char temp = s[i];
                    s[i] = c;
                    v.push_back(s);
                    s[i] = temp;
                }
            }
        }
        
        return v;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,int> mp;
        for(auto val:bank) mp[val]++;
        queue<string> q;
        map<string,int>dist;
        q.push(start);
        dist[start] = 0;
        while(!q.empty()){
            string s = q.front();
            q.pop();
            vector<string> v = generate(s);
            for(auto str:v){
                if( mp.find(str) == mp.end() ) continue;
                if(dist.find(str) == dist.end()){
                    dist[str] = 1+dist[s];
                    q.push(str);
                }
                else if(dist[str]>1+dist[s]){
                    q.push(str);
                    dist[str] = 1+dist[s];
                }
            }
        }
        if(dist.find(end) == dist.end()) return -1;
        return dist[end];
    }
};