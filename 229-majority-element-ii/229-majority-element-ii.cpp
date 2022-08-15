class Solution {
public:
    
    // similar to one with more than n/2
    // here we have two possible candidates
    
    bool check(int x,vector<int>&nums){
        int cnt = 0;
        int n = nums.size();
        for(auto val:nums) if(val == x) cnt++;
        return cnt > n/3;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        int cand1=1e9+1;
        int cand2=1e9+1;
        int freq1=0;
        int freq2=0;
        for(auto val:nums){
            if(val == cand1){
                freq1++;
            }
            else if(val == cand2){
                freq2++;
            }
            else if(freq1 == 0){
                cand1 = val;
                freq1=1;
            }
            else if(freq2 == 0){
                cand2 = val;
                freq2=1;
            }
            else{
                freq1--;
                freq2--;
            }
        }
        
        vector<int> ans;
        //cout<<cand1<<" "<<cand2;
        
        // note that voting algorithm only gives possible candidates and they are not guaranteed
        // so we have to check if candidates are valid
        if(check(cand1,nums)) ans.push_back(cand1);
        if(check(cand2,nums)) ans.push_back(cand2);
        return ans;
    }
};