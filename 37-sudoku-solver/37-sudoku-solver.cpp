class Solution {
public:
    bool isValid(int row,int col,vector<vector<char>>& board,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
                return false;
            if(board[i][col]==c)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board )
    {
        
         for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(i,j,board,c)){
                            //cout<< c<<endl;
                            board[i][j]=c;
                            if(solve(board ))
                                return true;
                            board[i][j]='.'; // undoing the earlier marked place
                        }
                    }
                    //im unable to fill  cell so im returning false;
                    return false;
                }
            }
        }
        //bhenchod i have filled all cells so returning true
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
     solve(board);
    }
};