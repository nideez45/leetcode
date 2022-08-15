class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // to store possible candidate for majority element
        int cand;
        
        // current freq of candidate
        int freq=0;
        for(auto val:nums){
            // if freq of candidate is zero then current element becomes possible candidate
            if(freq == 0){
                cand = val;
                freq = 1;
            }
            // if current element not same as candidate it votes against it
            else if(val!=cand){
                freq--;
            }
            // if current element is same as candidate freq increases
            else{
                freq++;
            }
        }
        return cand;
    }
};