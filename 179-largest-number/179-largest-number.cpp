 bool comp(int a,int b){
        string s = to_string(a);
        string t = to_string(b);
        return s+t>t+s;
    }

class Solution {
public:
     
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        bool ok = false;
        for(auto n:nums){
            if(n) ok = true;
        }
        if(!ok) return "0";
        string ans;
        for(auto n:nums){
            for(auto c:to_string(n)){
                ans.push_back(c);
            }
        }
        
        return ans;
    }
};