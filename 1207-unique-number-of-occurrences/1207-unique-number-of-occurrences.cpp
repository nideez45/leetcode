class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto val:arr) mp[val]++;
        map<int,int> mp1;
        for(auto pr:mp) mp1[pr.second]++;
        return mp.size() == mp1.size();
    }
};