struct  Node{
    int x,y,time;
    Node(int x,int y,int time){
        this->x=x,this->y=y,this->time=time;
    }
};
int visited[12][12];
int cnt=0;
class Solution {
    
        
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int total_oranges=0,r=grid.size(), c=grid[0].size(),max_time=0 ;
        queue<Node> q;
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                total_oranges+=(grid[i][j]>0)  , 
                visited[i][j]=0  ;
                if(grid[i][j]==2) q.push( Node(i,j,0));
            }
        
        for(cnt=0;!q.empty();){
            auto top=q.front();
            q.pop(),cnt++;
            
            int time=top.time,x=top.x,y=top.y;
            max_time=max(max_time,time);
            int directions[]={-1, 0 ,1, 0 ,-1}; // it will cover all 4 directions
            for(int i=0;i<4;i++){
                int newX=x+directions[i],newY=y+directions[i+1];
                if(newX>-1 and newX<r and newY>-1 and newY<c 
                   and !visited[newX][newY] and grid[newX][newY]==1 ){
                    visited[newX][newY]++, 
                    grid[newX][newY]=2,
                    q.push(Node(newX, newY, time+1))   ;
                }
            }
            
        }
        
        return total_oranges==cnt?max_time:-1;
    }
};