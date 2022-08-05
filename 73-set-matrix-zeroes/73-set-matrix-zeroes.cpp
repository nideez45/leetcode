class Solution {
public:
    
    // O(nm) Time and O(1) space
    // try to extend the linear space idea
    // instead of using additional space try to store whether a row or column has to be made 0
    // in first row and first column itself
    
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool first_row = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    if(i == 0) first_row = true;
                    else matrix[i][0] = 0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[i][0] == 0){
                for(int j=0;j<m;j++) matrix[i][j] = 0;
            }
        }
        
        for(int j=0;j<m;j++){
            if(matrix[0][j] == 0){
                for(int i=0;i<n;i++) matrix[i][j] = 0;
            }
        }
        
        if(first_row) for(int j=0;j<m;j++) matrix[0][j] = 0;
        
    }
};