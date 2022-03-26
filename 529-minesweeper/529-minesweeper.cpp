//to go into all 8 directions
int dir[8][2] = {{1, 1}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {1, -1}};
class Solution {
     /*
     Points to ponder 
     'E' is kind of unvisited stuff here
     
     */
    void dfs(vector<vector<char>> &board,int x,int y){
        /*
        1. find whether any of the adjacent guy s of board[x][y] is holding 'M'                stuff any cnt no of such adj guy's
        2. if cnt >0 so update the value of board[x][y] with cnt and return from there as its mentioned we can't further advance in path.
        3. else mark board[x][y]='B' and we can recursively advance towards its adjacents
        
        */
        
        board[x][y]='0';
        
        /*Find the cnt */
        for(int i=0;i<8;i++){
            int newX=x+dir[i][0],
                newY=y+dir[i][1];
            if(newX>=0 && newY>=0 && newX < board.size() && newY < board[0].size() && board[newX][newY] == 'M')
                board[x][y]++;
        }
        
        if(board[x][y]>'0') {
            return ;
        }
        // if still you have board[x][y]>0 then mark board[x][y]='B'
        board[x][y]='B';
        //Now let me recursively travel to all its adjacents guys
        for(int i=0;i<8;i++){
            int newX=x+dir[i][0],
                newY=y+dir[i][1];
            if(newX>=0 && newY>=0 && newX < board.size() && newY < board[0].size() && board[newX][newY] == 'E')
                dfs(board,newX,newY);
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
	
	//check if input coordinates contains mine or not if yes simply change and return
    
	if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]]='X';
            return board;
        }
		// else call dfs on board
		
        dfs(board,click[0],click[1]);
        return board;
    }
};
/*

E E E E E
E E M E E
E E E E E
E E E E E

B 1 E 1 B
B 1 M 1 B
B 1 1 1 B
B B B B B



another matrix input
is vale metrix mei at very first click was on the M so ye expolde ho gya so that why i return ed it as it is 
B 1 E 1 B
B 1 M 1 B
B 1 1 1 B
B B B B B 



*/