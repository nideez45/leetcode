class Solution {
public:
    //
    int threeSumMulti(vector<int>& arr, int target) {
        int i=0;
        int n = arr.size();
        long ans = 0;
        int mod = 1e9+7;
        sort(arr.begin(),arr.end());
        while(i<n){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sm = arr[i]+arr[j]+arr[k];
                if(sm == target){
                    if(arr[j] == arr[k]){
                        int cnt = 0;
                        while(j<=k){
                            cnt++;
                            j++;
                        }
                        ans+= (cnt*(cnt-1))/2;
                        ans%=mod;
                    }
                    else{
                    int temp1 = 0;
                    int temp2 = 0;
                    int val1 = arr[j];
                    int val2 = arr[k];
                    while(val1 == arr[j]){
                        j++;
                        temp1++;
                    }
                    while(val2 == arr[k]){
                        k--;
                        temp2++;
                    }
                        ans+= temp1*temp2;
                        ans%=mod;
                    }
                }
                else if(sm>target){
                    k--;
                }
                else j++;
            }
            i++;
        }
        return ans;
    }
};