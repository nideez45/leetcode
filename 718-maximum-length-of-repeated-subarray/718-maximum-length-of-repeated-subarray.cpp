class Solution {
public:
    // binary search on the length
    // can check if a length is possible with hashing
    
    int getHash(int l,int r,vector<int> &hash,vector<int> &pk){
        int n = hash.size();
        int mod = 1e9+7;
        if(l == 0) return hash[r];
        return (hash[r]-((1LL*hash[l-1]*pk[r-l+1])%mod)+mod)%mod;
    }
    
    bool check(int len,vector<int>&hash1,vector<int>&pk1,vector<int>&hash2,vector<int>&pk2){
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=len-1;i<hash1.size();i++){
            // starting at index i-k+1 and ending at index i
            mp1[getHash(i-len+1,i,hash1,pk1)]++;
        }
        for(int i=len-1;i<hash2.size();i++){
            mp2[getHash(i-len+1,i,hash2,pk2)]++;
        }
        for(auto pr:mp1){
            if(mp2.find(pr.first) != mp2.end()) return true;
        }
        return false;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int p = 131;
        int mod = 1e9+7;
        vector<int> pk1;
        vector<int> pk2;
        vector<int> hash1;
        vector<int> hash2;
        pk1.resize(nums1.size());
        hash1.resize(nums1.size());
        pk2.resize(nums2.size());
        hash2.resize(nums2.size());
        hash1[0] = nums1[0]+1;
        hash2[0] = nums2[0]+1;
        pk1[0] = pk2[0] = 1;
        for(int i=1;i<nums1.size();i++){
            hash1[i] = ((1LL*hash1[i-1]*p)%mod + (nums1[i]+1))%mod;
            pk1[i] = (1LL*pk1[i-1]*p)%mod;
        }
        for(int i=1;i<nums2.size();i++){
            hash2[i] = ((1LL*hash2[i-1]*p)%mod + (nums2[i]+1))%mod;
            pk2[i] = (1LL*pk2[i-1]*p)%mod;
        }
        int ans = 0;
        int lo = 1;
        int hi = min(nums1.size(),nums2.size());
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid,hash1,pk1,hash2,pk2)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
      //  cout<<getHash(2,3,hash1,pk1)<<" "<<getHash(0,1,hash2,pk2)<<'\n';
        return ans;
    }
};