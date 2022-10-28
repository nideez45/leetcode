class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<int,int>> v;
        map<string,vector<string>> mp;
        for(string val:strs){
            string s = val;
            sort(s.begin(),s.end());
            mp[s].push_back(val);
        }
        vector<vector<string>> ans;
        for(auto pr:mp){
            ans.push_back(pr.second);
        }
        return ans;
    }
};