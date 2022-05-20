class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size(),c=obstacleGrid[0].size();
        //Try to make use if given grid
        /*
        2 1 1
        1 A 1
        1 1 1
        */
        //if the bottom right holds obstacle then its not wise choice to make progress
        if( obstacleGrid[0][0] || obstacleGrid[r-1][c-1]) return 0;
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(obstacleGrid[i][j])
                    obstacleGrid[i][j]=-1;
        obstacleGrid[r-1][c-1]=1; 
        vector<vector<long>> grid(r,vector<long>(c));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(obstacleGrid[i][j])
                    grid[i][j]=obstacleGrid[i][j];
        
        
        cout<<"printing"<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(grid[i][j]<0) continue; //if the grid cell is blocked then ignore it.
                // grid[i][j]+=grid[i+1][j]+grid[i][j+1];
                // Adding down cell
        grid[i][j]=( grid[i][j]  + ( ( i+1 <r  && grid[i+1][j]>0 ) ? grid[i+1][j] : 0)  )   ;
                // Adding right cell
                grid[i][j]=(grid[i][j] + (( j+1 <c  && grid[i][j+1]>0 ) ? grid[i][j+1] : 0)) ;
            }
        }
        
        return  (int)grid[0][0];
        
        
            
            
    }
};