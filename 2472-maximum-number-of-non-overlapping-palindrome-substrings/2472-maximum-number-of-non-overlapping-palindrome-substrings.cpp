bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}

class Solution {
public:
    string s;
int n;
 
int dp[2020][2020];
 
int rec(int l,int r){
    
    if(l>=r) return 1;
 
    if(dp[l][r] != -1) return dp[l][r];
    int ans = false;
    if(s[l] == s[r] && rec(l+1,r-1)) ans = true;
 
    return dp[l][r] = ans;
 
}

    int maxPalindromes(string _s, int k) {
        s = _s;
        n = s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) dp[i][j] = -1;
        }
    vector <pair<int,int>> intervals;
    for(int i=0;i<n;i++){
        bool ok = false;
        for(int j=i;j<n;j++){
            if(ok) break;
            if(j-i+1>=k){
            if(rec(i,j) && j-i+1>=k){
                intervals.push_back({i,j});
                ok = true;
            }
            }
        }
    }
     //   for(auto pr:intervals) cout<<pr.first<<" "<<pr.second<<'\n';
        if(intervals.size() == 0) return 0;
    sort(intervals.begin(),intervals.end(),comp);
        int cnt = 0;
     int R = intervals[0].second;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].first<=R){
                cnt++;
            }
            else{
                R = max(R,intervals[i].second);
            }
        }
        return intervals.size()-cnt;
    }
};