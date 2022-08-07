bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int R = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<R){
                cnt++;
            }
            else{
                R = max(R,intervals[i][1]);
            }
        }
        return cnt;
    }
};