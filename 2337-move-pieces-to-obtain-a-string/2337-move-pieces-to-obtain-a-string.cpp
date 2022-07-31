class Solution {
public:
    bool canChange(string start, string target) {
        vector<pair<char,int>> v1;
        vector<pair<char,int>> v2;
        int n = start.size();
        for(int i=0;i<n;i++){
            if(start[i] != '_') v1.push_back({start[i],i});
        }
        for(int i=0;i<n;i++){
            if(target[i] != '_') v2.push_back({target[i],i});
        }
        if(v1.size() != v2.size()) return 0;
        else{
            for(int i=0;i<v1.size();i++){
                if(v1[i].first != v2[i].first) return 0;
                else{
                    int idx1 = v1[i].second;
                    int idx2 = v2[i].second;
                    if(v1[i].first == 'L'){
                        if(idx1<idx2) return 0;
                    }
                    else{
                        if(idx1>idx2) return 0;
                    }
                }
            }
            return 1;
        }
    }  
};