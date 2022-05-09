int dp[101][101][205]; //its called 3-d dp because 3 states are changing  here
int m,n;
class Solution {
    int dfs(vector<vector<char>>& grid,int i = 0, int j = 0, int bal = 0){
        
        if(i>=m || j>=n)
            return 0;
        bal+=grid[i][j]=='('?1:-1;
        //base cases where i want my execution to not move ahead
        // if(bal<0 || grid[0][0] ==')' || grid[m-1][n-1] =='(' )
        //     return  0;
        
        if( bal<0 )
            return  0;
        if(dp[i][j][bal]!=-1)
            return dp[i][j][bal];
        if(i==m-1 && j==n-1 ) 
            return  !bal ;
        
        
        
        
        
        //Now,  remaining task is to explore right or down states
        if(  j+1<n &&  dfs(grid,i,j+1,bal)   )
            return dp[i][j][bal]=true;
        
        if(i+1<m && dfs(grid,i+1,j,bal) )
            return dp[i][j][bal]=true;
        
        //nonw of the paths brought true response thats why returning false;
        return dp[i][j][bal]=false ;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid ) {
        
        /*
        How will you make progress in thhi sproblem???
        I'll check if (m-1,n-1)  cell is having opening bracket 
        then return false;
        or
        I'll check if (0,0) cell is having closing bracket 
        then return false;
         
        It seems that algorithm i. thought was wrong
         
         
        ( ( ( 
        ) ( ) 
        ( ( ) 
        ( ( )
        
        1     0    0
        0     0    0
        1     2    1
        2     3    -1
        
        intuition if at the end i have got 0 at m-1,n-1 cell theh return true;
        Fact: balance is the combination of openoing and closing braces, if closing braces are more then return false because balcance will. go negative in that case
        */
        m=grid.size(),
        n=grid[0].size();
        memset(dp,-1,sizeof dp);
        return dfs(grid);
        
        
    }
};