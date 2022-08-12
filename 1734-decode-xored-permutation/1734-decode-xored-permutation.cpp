class Solution {
public:
    
    // p1^p2 p2^p3 p3^p4 p4^p5
    
    vector<int> decode(vector<int>& encoded) {
        int xr = 0;
        int n = encoded.size()+1;
        for(int i=1;i<=n;i++){
            xr = (xr^i);
        }
        int first = xr;
        for(int i=0;i<n-1;i++){
            if(i%2) first^=encoded[i];
        }
        vector<int> ans;
        ans.push_back(first);
        for(int i=0;i<n-1;i++){
            ans.push_back(ans.back()^encoded[i]);
        }
        return ans;
    }
};