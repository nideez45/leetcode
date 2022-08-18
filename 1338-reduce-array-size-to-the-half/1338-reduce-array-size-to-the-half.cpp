class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int freq[100001] = {0};
        for(int i=0;i<n;i++) freq[arr[i]]++;
        vector<int> v;
        for(int i=0;i<=100000;i++){
            v.push_back(freq[i]);
        }
        sort(v.rbegin(),v.rend());
        int target = n/2;
        int present = 0;
        int i=0;
        while(present<target){
            present+=v[i];
            i++;
        }
        return i;
    }
};