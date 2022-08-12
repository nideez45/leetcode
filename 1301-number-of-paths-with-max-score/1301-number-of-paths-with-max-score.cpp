class Solution {
public:
    
    /*
    E23
    2X2
    12S
    */
    
    const int mod = 1e9+7;
    
    bool check(int x,int y,int n){
        return (x>=0 && y>=0 && x<n && y<n);
    }
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int dp1[n][n]; // best score from i,j to n-1,n-1
        int dp2[n][n]; // number of ways to get best score from i,j to n-1,n-1
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == n-1 && j == n-1){
                    dp1[i][j] = 0;
                    dp2[i][j] = 1;
                }
                else{
                    int mx = -1;
                    if(board[i][j] == 'X'){
                        dp1[i][j] = -100;
                        dp2[i][j] = 0;
                        continue;
                    }
                    if(check(i,j+1,n)){
                        if(dp1[i][j+1]>mx){
                            mx = dp1[i][j+1];
                            dp2[i][j] = dp2[i][j+1];
                            dp2[i][j]%=mod;
                        }
                        else if(dp1[i][j+1] == mx){
                            dp2[i][j] += dp2[i][j+1];
                            dp2[i][j]%=mod;
                        }
                    }
                    if(check(i+1,j,n)){
                        if(dp1[i+1][j]>mx){
                            mx = dp1[i+1][j];
                            dp2[i][j] = dp2[i+1][j];
                            dp2[i][j]%=mod;
                        }
                        else if(dp1[i+1][j] == mx){
                            dp2[i][j] += dp2[i+1][j];
                            dp2[i][j]%=mod;
                        }
                    }
                    if(check(i+1,j+1,n)){
                        if(dp1[i+1][j+1]>mx){
                            mx = dp1[i+1][j+1];
                            dp2[i][j] = dp2[i+1][j+1];
                            dp2[i][j]%=mod;
                        }
                        else if(dp1[i+1][j+1] == mx){
                            dp2[i][j]+=dp2[i+1][j+1];
                            dp2[i][j]%=mod;
                        }
                    }
                    
                    if(mx != -1){
                        dp1[i][j] = mx;
                        if(i!=0 || j!=0) dp1[i][j] += (board[i][j]-'0');
                    }
                    else dp1[i][j] = -100;
                }
            }
        }
        vector<int> ans;
        if(dp1[0][0] == -100) dp1[0][0]=0;
        ans.push_back(dp1[0][0]);
        ans.push_back(dp2[0][0]);
        return ans;
    }
};