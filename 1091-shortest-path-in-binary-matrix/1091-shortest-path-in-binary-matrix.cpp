struct node{
    int i,j;
    node(int i,int j){
        this->i=i,
        this->j=j;
    }
};
int DIR[]={-1,0,1,0 ,-1,-1,1,1,-1};
 vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
class Solution {

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size() ,steps=-1;
        if( grid[0][0]  or grid[n-1][n-1] ) return -1;
        /* 
               
        */
        queue<node> q;
        q.push( node(0,0) );
        grid[0][0]=1;//marking start position as topmost left position as 1
        while(q.size()){
            int r=q.front().i,
                c=q.front().j;
            if(r==n-1 and c==n-1){  steps=grid[r][c];break;}
            // steps++;
            q.pop();
            
            for(auto direction:directions){
                int x=r+direction[0],
                    y=c+direction[1];
                if(x>-1 && x<n && y>-1 && y<n && !grid[x][y])
                    q.push(node(x,y)), grid[x][y]=grid[r][c]+1;
            }
            
        }
        //priniting the matrix 
        
        for(auto i:grid){ 
            for(auto j:i)
                cout<<j<<" ";
            cout<<endl;
        }
        return steps;
    }
};