class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto pr:mp){
            vector<int> temp;
            temp = pr.second;
            sort(temp.rbegin(),temp.rend());
            mp[pr.first] = temp;
        }
        //for(auto v:mp[-1]) cout<<v<<" ";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};