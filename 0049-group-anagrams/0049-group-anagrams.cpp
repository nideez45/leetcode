class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>> v;
       
        for(string &val:strs){
            string s = val;
            sort(s.begin(),s.end());
            v.push_back({s,val});
        }
        sort(v.begin(),v.end());
        vector<vector<string>> ans;
        int i=0;
        int n = strs.size();
        while(i<n){
            vector<string> temp;
            string cur = v[i].first;
            while(i<n && cur == v[i].first){
                temp.push_back(v[i].second);
                i++;
                
            }
           ans.push_back(temp);
        }
        return ans;
    }
};