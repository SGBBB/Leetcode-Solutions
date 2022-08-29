class Solution {
    void eraseIslands(vector<vector<char>>& grid,int i,int j){
        int dir[]={-1,0,1,0,-1};//URDL
        //make itself 0 
            grid[i][j]='0';
        int r=grid.size(),c=grid[0].size();
        //travel to 4 directions
        for(int k=0;k<4;k++){
            
            int newi=i+dir[k],newj=j+dir[k+1];
            //ensuring whether coming cell is under boundry and is '1'
            if(min(newi,newj)>-1 && newi<r && newj<c && grid[newi][newj]=='1'){
                eraseIslands(grid,newi,newj);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
         
    }
};