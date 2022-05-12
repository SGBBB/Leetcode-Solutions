// int maxi=-1000008;
int dp[70][70][70];
class Solution {
int dfs( vector<vector<int>>& grid , int i,int j1 ,int j2 ){
        int r=grid.size(),c=grid[0].size();
        if( min({i,j1,j2})>=0 && i<r && max(j1,j2)<c ){
            //Can i assume that both guys reach end at the same moment?Yes i observe
            
            if(dp[i][j1][j2]!=-1)
                return dp[i][j1][j2];
            int cnt=0;
            if(  j1==j2 )
                cnt+=grid[i][j1];
            else cnt+=grid[i][j1]+grid[i][j2];
            
            if(i==r-1  ) 
                return cnt;
            int maxi=0;
            for(int dj1=-1;dj1<=1;dj1++)
                for(int dj2=-1;dj2<=1;dj2++)
                    maxi=max(maxi,dfs(grid,i+1,j1+dj1,j2+dj2) );
            
            return dp[i][j1][j2]=cnt+maxi;
            
            
            
            
        }
    return -1e8;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        return  dfs(grid,0,0,grid[0].size()-1);
    }
};
/*

How will you approach thihs problem???
I think I have solved similar problem recently 
What brute force approach is comning to my brain???
are these both guys taking equal steps???
I think brute force solution will have complexity as 3^(n) + 3^(n).

*/