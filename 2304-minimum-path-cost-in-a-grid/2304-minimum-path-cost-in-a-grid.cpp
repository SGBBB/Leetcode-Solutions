int memo[51][51];
class Solution {
    int dfs(vector<vector<int>>& grid,  int idx=0,int col=0){
        
        int r=grid.size() ,c=grid[0].size();
        
        if( idx==r-1 && (col >= 0 && col <= c - 1) ){
            
            return grid[idx][col];
        }
        if ( idx==r  || (col < 0 || col == c) )
            return 1e8;   // taking max =6000 according to constraints
        if(memo[idx][col]!=-1)
            return memo[idx][col];
        int minCost=6000;
        for(int i=0;i<c;i++){
            int curMoveCost=  moveCost[ grid[idx][col] ][i]  ;
            
            
            //Recursive funcition is returning the min. optimal Value at below cell
            int curMinCost=(grid[idx][col])+ curMoveCost + dfs(grid, idx+1,i);
            minCost=min({minCost,curMinCost});
            
        }
        return memo[idx][col]=minCost;
    }
    vector< vector<int> >  moveCost;
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        //Seems like Smple dp problem
        /*
        Time compexity is (n^m) as at every step I've got 'n' choices.
        5 1 2 
        4 0 3
        
        */
        int ans = INT_MAX;
        memset(memo,-1,sizeof memo );
        this->moveCost=moveCost;
        for (int i = 0; i < grid[0].size(); i++)
        {
		     // as we have to start from first row so we call for (0,0)  (0,1)  (0,2) ....
            ans = min(ans, dfs(grid, 0, i ));
			
        }
        return ans;
        return dfs(grid );
    }
};
class Solution1
{
public:
    int row, col;
    int memo[51][51];
    int pass(vector<vector<int>> &m, int i, int j, vector<vector<int>> &Cost)
    {
        if (i == row - 1 and (j >= 0 and j <= col - 1))
            return m[i][j];
        if (i == row || (j < 0 || j == col))
            return 6000;   // taking max =6000 according to constraints
        if (memo[i][j] != -1)
            return memo[i][j];
        int ans = 6000;
        for (int ii = 0; ii < col; ii++)   
        {
            ans = min(ans, (m[i][j] + Cost[m[i][j]][ii] + pass(m, i + 1, ii, Cost)));
        }
        return memo[i][j] = ans;
    }
    int minPathCost(vector<vector<int>> &matrix, vector<vector<int>> &moveCost)
    {
        int ans = INT_MAX;
        memset(memo, -1, sizeof(memo));
        row = matrix.size();
        col = matrix[0].size();
        // return pass(matrix, 0, 1, moveCost);
        for (int i = 0; i < col; i++)
        {
		     // as we have to start from first row so we call for (0,0)  (0,1)  (0,2) ....
            ans = min(ans, pass(matrix, 0, i, moveCost));
			
        }
        return ans;
    }
};