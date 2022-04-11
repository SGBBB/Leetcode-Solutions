class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        k=k%(m*n);
        // by doing mod im unecessary ignoring extra moves for a digit
        //Hint is that consider it as a 1d matrix
        while(k-- >0 ){
            vector<int> last_col;
            //This operation is gonna take  linear tc
            for(int i=0;i<m;i++){
                last_col.push_back(grid[i][n-1]);
            }
            //This operation is gonna take  O(n^2) tc
            for(int i=0;i<m;i++){
                for(int j=n-1;j>0;j--)
                    grid[i][j]=grid[i][j-1];
            }
            //This operation is gonna take  O(n^2) tc
            for(int i=1;i<m;i++)
                grid[i][0]=last_col[i-1];
            grid[0][0]=last_col.back();
        }
        return grid;
        
        
    }
};
/*
we are given k that k must be smaller than m*n
becoz as our observation states that any guy in a matrix can change atmost
m*n positions after he is done changing m*n posiitions then he will again sit in its original position.


*/