class Solution {
public:
    
    
    long long smallestNumber(long long num) {
        int sign = 1;
        if(num<0) sign = -1;
        num = abs(num);
        int freq[10] = {0};
        while(num){
            freq[num%10]++;
            num/=10;
        }
        long long ans = 0;
        if(sign == 1){
          for(int i=1;i<10;i++){
              if(freq[i]){
                  ans = i;
                  freq[i]--;
                  break;
              }
          }
          for(int i=0;i<freq[0];i++) ans*=10;
          for(int i=1;i<10;i++){
              for(int j=0;j<freq[i];j++){
                  ans*=10;
                  ans+=i;
              }
          }
        }
        else{
           for(int i=9;i>=0;i--){
               for(int j=0;j<freq[i];j++){
                   ans*=10;
                   ans+=i;
               }
           } 
            ans*=-1;
        }
        return ans;
    }
};