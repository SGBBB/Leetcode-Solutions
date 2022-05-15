int dir[]={-1,0,1,0,-1};
class Solution {
public:
    /*
    
    How will i make progress in this problem????
    Initially i need to find the regions which are connected by x in its borders
    Should i run bfs starting from border nodes and insert all  its neighbouring node in set data structures
    I think this makes sense
    But what will. be the overall time cmoplexity:::
    time complexity: O(r*c)
    
    O X X X
    O O O O
    X X O O
    X O X O
    
    */
    
    void bfs(vector<vector<char>>& board,vector<int> points){
        int r=board.size() , c=board[0].size();
        queue< vector<int> > q;
        cout<<"received "<<points[0]<<" "<<points[1] <<endl;
        board[points[0]][points[1]]='B';
        q.push({points[0],points[1]});
        while( !q.empty() ){
            auto front=q.front(); q.pop();
            int i=front[0],
                j=front[1];
            for(int k=0;k<4;k++){
                int newi=i+dir[k],newj=j+dir[k+1];
                if( min(newi,newj)<0  || newi>=r || newj>=c || 
                    board[newi][newj]=='X' || board[newi][newj]=='B'
                  )
                    continue;
                board[newi][newj]='B',q.push({newi,newj});
                
            }
            
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size() , c=board[0].size();
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(board[i][j]=='X' || board[i][j]=='B') continue;
                if( i==0 || i==r-1  )
                    bfs(board,{i,j});
                else{
                    if(!j || j==c-1)
                        bfs(board,{i,j}) ;
                }
            }
        
        //finally chagning the values
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(board[i][j]=='O' )
                    board[i][j]='X';
                if(board[i][j]=='B')
                    board[i][j]='O';
            }
    }
        
};