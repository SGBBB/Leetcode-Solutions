class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,multiset<int>> M;
        int r=mat.size(),c=mat[0].size();
        //storing elements corresponding to diagonal identifier
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                M[i-j].insert(mat[i][j]);
            }
        }
        //put sorted elements into their appropriate position
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mat[i][j]=*M[i-j].begin();
                M[i-j].erase(M[i-j].begin());
            }
        }
        
        return mat;
        
    }
};