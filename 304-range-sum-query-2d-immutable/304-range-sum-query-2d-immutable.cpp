class NumMatrix {
    vector<vector<int>> matrix;
    int r,c;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        this->r=r,this->c=c;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                int upValue=(i>0)?matrix[i-1][j]:0,
                    leftValue=(j>0)?matrix[i][j-1]:0,
                    diagonalValue=(min( {i,j} )>0)?matrix[i-1][j-1]:0;
                matrix[i][j]+=upValue+leftValue-diagonalValue ;
            }
        this->matrix=matrix;     
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        // for(auto it:matrix){
        //     for(int val:it)
        //         cout<<val<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;cout<<endl;cout<<endl;
        int upValue=(row1>0)?matrix[row1-1][col2]:0,
            leftValue=(col1>0)?matrix[row2][col1-1]:0,
            diagonalValue=(min( {row1,col1} )>0)?matrix[row1-1][col1-1]:0;
        sum=matrix[row2][col2]-(upValue+leftValue-diagonalValue);
        
        return sum;
    }
    /*
    
     3  0  1  4  2  
     5  6  3  2  1  
     1  2  0  1  5  
     4  1  0  1  7  
     1  0  3  0  5 
     
     PRefix Sum:
     
       
     
     
     intuition: Every diagonal is gonna carry something.
     If Im given 2 coordinates then I can easily figure out other 2
     
    */
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */