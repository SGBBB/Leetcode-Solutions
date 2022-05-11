int dp[51][51][51] ;
class Solution {
    /* 
    
    1   1 -1
    1  -1  1
    -1  1  1
    
    How will I think about  solving this problem???
    
    There are atmost 2500 cells 
    So im conofident to apply recursion here.
    
    Some corner case coming to my brain are if [n-1,n-1] hold some thorns then return 0;
    
    
    Note:Without memorization time complexity was O( 4^(N*N) ) ;
    becoz for every cell you are moving in atmost 4 directions then again these newly generated cells will proliferate in 4 directions.
    [Cell]->[Cell]->
     |       |
     |       v
     |
     v
     [Cell]->
     |
     v
     
     
     Same movement we will face while trailing back as well
     
     After doing optimization and memorization we have reduced time complexity to c ->
     and further more opotimization to O(n^3);
     
    */
    
public:
    int solve(vector<vector<int>>& grid,int r1,int c1,int r2 ,int r,int c )
{
    int c2=r1+c1 -r2; //since r1+c1==r2+c2 try to 
    if(max(r1,r2)<r && max(c1,c2)<c  && grid[r1][c1]!=-1 && grid[r2][c2]!=-1 ) {
        //If any guy visits the end cell then I can assume that other guy has also visited end cell
        if(dp[r1][c1][r2]!=-1)
            return dp[r1][c1][r2];
        if(r1==r-1 && c1==c-1)
            return grid[r1][c1];
        
        int cherries=0;
        // if both guys lie on the same cell then add cherries only once
        if(r1==r2 && c1==c2) 
            cherries+=grid[r1][c1];
        else 
            cherries+=grid[r1][c1]+grid[r2][c2];
        
        //exploring the directions
        int con1=solve(grid,r1,c1+1,r2,r,c); // right,right
        int con2=solve(grid,r1+1,c1,r2+1,r,c); // down,down
        int con3=solve(grid,r1+1,c1,r2,r,c); // down,right
        int con4=solve(grid,r1,c1+1,r2+1,r,c); // right,down
        cherries+=max( {con1,con2,con3,con4} );
        return dp[r1][c1][r2]=cherries;
        
    }
    //If you are moving in unfavourable conditions(like movign out of bounds or moving on thorn's) then kindly return the most smallest value 
    return INT_MIN;
}


int cherryPickup(vector<vector<int>>& grid) {
   
   int n=grid.size();
   
   // vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
    memset(dp,-1,sizeof dp);
    
   int ans=solve(grid,0,0,0,grid.size(),grid[0].size() );
   // cout<<" ans "<<" "<<ans<<endl;
   if(ans < 0)
       return 0;
    
   return ans;
}
};