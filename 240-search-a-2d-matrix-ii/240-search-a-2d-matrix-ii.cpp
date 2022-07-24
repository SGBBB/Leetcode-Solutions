class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // O(300log300)
        /*
        
        If 5 is > guys sitting at the last column then it wil not be present anywhere
        
        */
        int m=matrix.size(),n=matrix[0].size();
        if(target>matrix[m-1][n-1]) //becoz bottom right guy is the biggest among all
            return 0;
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j]==target)
                return 1;
            // if target is greater than I ll not be able to locate target in same row
            else if(target>matrix[i][j])
                i++;
            else
                j--;
        }
        //I was unbable to locate key in the matrix
        return 0;
    }
};