class Solution {
public:
    
    // O(nm) Time and O(n+m) space
    // use two array of size n amd m to determine whether a patricular row
    // or column has to be made into 0
    
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v1(n,0);
        vector<int> v2(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    v1[i] = 1;
                    v2[j] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(v1[i]){
                for(int j=0;j<m;j++) matrix[i][j] = 0;
            }
        }
        for(int j=0;j<m;j++){
            if(v2[j]){
                for(int i=0;i<n;i++) matrix[i][j] = 0;
            }
        }
        
    }
};