class Solution {
public:
    
    vector<int> nums = {1,5,10,50,100,500,1000};
    unordered_map<int,char> mp;
    
    string find(int num){
        if(num == 0){
            return "";
        }
        char to_put;
        int cnt;
        int choice ;
        string ans;
        
        for(int i=6;i>=0;i--){
            if(num/nums[i]){
                choice = i;
                to_put = mp[nums[i]];
                cnt = num/nums[i];
                break;
            }
        }
        if(choice%2){
            if(num/nums[choice-1] == 9){
                ans.push_back(mp[nums[choice-1]]);
                ans.push_back(mp[nums[choice+1]]);
                cnt = 9;
                choice -=1;
            }
            else{
                for(int i=0;i<cnt;i++) ans.push_back(to_put);
            }
        }
        else{
            if(num/nums[choice] == 4){
                ans.push_back(mp[nums[choice]]);
                ans.push_back(mp[nums[choice+1]]);
            
            }
            else{
                for(int i=0;i<cnt;i++)ans.push_back(to_put);
            }
        }
        return ans+find(num-cnt*nums[choice]);
    }
    
    string intToRoman(int num) {
        mp[1] = 'I';
        mp[5] = 'V';
        mp[10] = 'X';
        mp[50] = 'L';
        mp[100] = 'C';
        mp[500] = 'D';
        mp[1000] = 'M';
        return find(num);
    }
};