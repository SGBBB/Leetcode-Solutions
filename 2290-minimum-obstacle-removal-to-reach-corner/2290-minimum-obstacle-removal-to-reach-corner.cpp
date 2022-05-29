int dir[]={-1,0,1,0,-1}; //URDL
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        /*
        If I have got only 1 component then i dont need to apply any bfs on obstacles
        Subtle observation:
        
        
         0 1 1  
         1 0 1  
         1 1 0
         
         0 1 0  
         1 1 1  
         1 1 0
         
         
         0 1 0  
         1 1 1  
         0 1 0
         
         
         0 1 1 1 1 0  
         1 1 1 0 1 0
         1 1 1 0 1 0
         Ans -> 4
         Now, I'm gonna think pure bfs technique to silve this problem
         Hint is to apply dikstras algo
         
         
         
         
        */
        int r=grid.size(), c=grid[0].size();
//         for(auto &row:grid){
//             for(auto &curCell:row){
//                 if(curCell)
                    
//             }
//         }
        set<vector<int>>S; // {cost,i,j}
        S.insert({0,0,0});
        int vis[r][c];
        memset(vis,0,sizeof vis);
        
        
        while(!S.empty()){
            auto topElement=*S.begin();
            S.erase(S.begin());
            int cost=topElement[0],
                i=topElement[1],
                j=topElement[2];
            vis[i][j]=1;//mark cur cell visited
            if(i==r-1 && j==c-1) 
                return cost;
            for(auto k=0;k<4;k++){
                int newi=i+dir[k],
                    newj=j+dir[k+1];
                if(min(newi,newj)<0 || newi>r-1 || newj>c-1 ||  vis[newi][newj])
                    continue;
                // if new cell is obstacle then do cost+1
                int newCost=(grid[newi][newj]==1)?cost+1:cost;
                S.insert({newCost,newi,newj}),
                vis[newi][newj]=1;    
            }
            
        }
        
        
        return -1;
    }
};