
class Solution {
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
         I'm required to mask the new value of digits
          0->  0  is called 0
          1->  1  is called 1
          0->  1  is called 2
          1->  0  is called 3
         
         <2 or >3 live neighbourer die
         2 or 3 live neighbourer live
         dead cell with 3 live neighbourer become live
         
        */
        vector<pair<int ,int> > dir=
        {{-1,0 } , { 1,0} , {0,-1} , {0,1} ,
         {-1,-1},{1,-1} , {-1,1}, {1,1}
        };
        
        int cnt=0, i=0, j=0,r=board.size(),c=board[0].size();
        for(;i<r;i++){
            for(j=0;j<c;j++){
                cnt=0;
                //
                for(auto [x,y] :dir){
                    x+=i , y+=j;
                    if( x>-1 and x<r and y>-1 and y<c){
                        
                        cnt+=( (board[x][y]==1) or (board[x][y]==3) );      
                    }   
                }
                cout<<cnt<<endl;
                if(board[i][j]==1) {
                    //Any live guy with cnt>3 or cnt<2 will die so assign board[i][j]=3
                        board[i][j]=(cnt>3 or cnt<2) ?3: 1;
                    }
                    else{
                        board[i][j]=(cnt==3) ?2: 0;
                    }
            }
            
        }
        for(auto &i:board){
            for(auto &j:i){
                // if val at cell isnt 1 or 0 
                if( !(j==0 or j==1 ) ){ 
                    j=(j==2) ?1: 0; 
                }
            }
        }
        
        
        /*filling the updated values */
        
    }
};