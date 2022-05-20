int dir[]={-1,0,1,0,-1};//URDL
/*
s 0 0
0 0 0
0 e -1

s 1 1
1 1 1
1 e 1
*/
class Solution {
    long dfs(vector<int> cur,vector<int> &end,vector<vector<int>>& grid,int nonObstacleCells){
        int r=grid.size(), c=grid[0].size() ;
        int i=cur[0],j=cur[1];
        cout<<i <<" "<<j <<endl;
        if(i==end[0] && j==end[1]){
            cout<<nonObstacleCells<<endl;
            // if i have reached the end cell then i'll check whether nonObstacleCells is 0
            return (nonObstacleCells<0);
        }
        long cnt=0;
        for(int k=0;k<4;k++){
            int newi=i+dir[k],
            newj=j+dir[k+1];
            //if new coordinate isnt a favourable cell then i'm simply ifnoring that cell
            if( min(newi,newj)<0 || newi>=r || newj>=c || grid[newi][newj]==-1 || 
              grid[newi][newj]==1 )
                continue;
            grid[newi][newj]=-1;
            cnt+=dfs({newi,newj},end,grid,nonObstacleCells-1);
            grid[newi][newj]=0;
        }
        return cnt;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int nonObstacleCells=0;
        int r=grid.size(), c=grid[0].size() ;
        vector<int> start(2),end(2);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    start[0]=i,start[1]=j;
                else if(grid[i][j]==2)
                    end[0]=i,end[1]=j;
                else //if current cell is 0 then do increment nonObstacleCells. 
                    nonObstacleCells+=(!grid[i][j]);
            }
        // cout<<"nonObstacleCells "<<end[0]<<" "<<end[0]<<endl;
        // cout<<"nonObstacleCells "<<nonObstacleCells<<endl;
        long cnt=dfs(start,end, grid,nonObstacleCells);
        return (int)cnt;
    }
};
/*


Should i consider some sub-matrix initially?

i can initiially cnt the non obstacle cells 
Try to use backtracking concept.



*/