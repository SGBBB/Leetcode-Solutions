```
void dfs(vector<vector<char>>& board, int r, int c){
int mine_cnt=0;
// this loop is to check if the current location contains any  mine in
//any of its 8 directions. If yes increase count of mine_cnt and
//also check if index doesn't go our of bounds
for(int i=0;i<8;i++){
int x = r + dir[i][0];
int y = c + dir[i][1];
if(x>=0 && y>=0 && x < board.size() && y < board[0].size() && board[x][y] == 'M')
mine_cnt++;
}
// if our mine_cnt if greater than 0 means we found a mine in any
//of its adjacent location so we change value of board[r][c] i.e. of that location
// and return because we can't go any further because we can go only if
// it has unrevealed empty cell i.e. 'E'.
if(mine_cnt>0){
board[r][c] = mine_cnt + '0';
return ;
}
// if we are that means we got 0 mine so change it to blank cell
board[r][c] = 'B';
// now here we will iterate to all its 8 directions if it in bounds and our next cell is unrevealed emoty cell i.e. 'E'
for(int i=0;i<8;i++){
int x = r + dir[i][0];
int y = c + dir[i][1];
​
if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == 'E')
dfs(board, x, y);
}
}
```