int directions[]={-1,0,1,0,-1}; // URDL
class Solution {
    
    int r,c;
    int findArea(vector<vector<int>> &grid,int i,int j){
        int curArea=1;
            for(int k=0;k<4;k++){
                int newi=i+directions[k],
                    newj=j+directions[k+1];
                //checking boundry conditions  ans ensuring we dont enter in cell having value 0
                if( min({newi,newj})<0  || newi>r-1 || newj>c-1 || 
                    grid[newi][newj]==0 )
                    continue;
                grid[i][j]=0; //marking cur cell visited 
                curArea+=findArea(grid,newi,newj);
                grid[i][j]=-1; //undo step
            }
        grid[i][j]=0;//marking current cell visited 
        return curArea;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         
        int maxArea=0;
        this->r=grid.size(),
        this->c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0 || grid[i][j]==-1) //component is already computed
                    continue;
                
                    
                int response=findArea(grid,i,j);
                cout<< grid[i][j]<<" "<< i<<" "<< j<<" "<<response<<endl;
                maxArea=max({maxArea,response});
                
            }
        }
        
        return maxArea;
        
        
    }
};