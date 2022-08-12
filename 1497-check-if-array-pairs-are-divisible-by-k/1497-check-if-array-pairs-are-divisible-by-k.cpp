class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0;i<n;i++) {
            arr[i]%=k;
            if(arr[i]<0) arr[i]+=k;
        }
        unordered_map<int,int> mp;
        for(auto val:arr) mp[val]++;
        int cnt = 0;
        cnt+=mp[0]/2;
        for(int i=1;i<k/2;i++){
            int j = k-i;
            cnt+=min(mp[i],mp[j]);
        }
        if(k%2 == 0){
            cnt+=(mp[k/2])/2;
        }
        else{
            cnt+=min(mp[k/2],mp[k/2+1]);
        }
        
        return cnt>=n/2;
    }
};