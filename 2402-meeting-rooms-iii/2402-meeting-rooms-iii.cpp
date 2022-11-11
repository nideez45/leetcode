class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
     //   for(auto v:meetings) cout<<v[0]<<" "<<v[1]<<'\n';
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> unused;
        int cnt[n];
        for(int i=0;i<n;i++) cnt[i] = 0;
        int un_used = 0;
        for(int i=0;i<meetings.size();i++){
           // if unused is present then directly put with same time as its end time
           // if no unused is present then calculate the time after which something which is unused will get free and put with updated time
            int start = meetings[i][0];
            while(pq.size() && pq.top().first<=start){
                auto pr = pq.top();
                pq.pop();
                unused.push({1LL*pr.second,1LL*pr.first});
            }
            if(unused.size()){
                auto pr = unused.top();
                unused.pop();
                int room_no =pr.first;
                cnt[room_no]++;
                pq.push({1LL*meetings[i][1],room_no});
            }
            else if(pq.size() && un_used==n){
                auto pr = pq.top();
                pq.pop();
                int room_no = pr.second;
                cnt[room_no]++;
                long long end_time = pr.first;
                long long duration = 1LL*meetings[i][1]-1LL*meetings[i][0];
                pq.push({1LL*end_time+1LL*duration,room_no});
            }
            else{
                cnt[un_used]++;
                pq.push({1LL*meetings[i][1],un_used});
                un_used++;
            }
        }
      //  for(int i=0;i<n;i++) cout<<cnt[i]<<" ";
        int mx = 0;
        int idx = n;
        for(int i=0;i<n;i++){
            if(cnt[i]>mx) {
                idx = i;
                mx = cnt[i];
            }
        }
        return idx;
    }
};