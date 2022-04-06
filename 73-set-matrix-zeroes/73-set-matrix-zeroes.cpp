class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1, r=matrix.size(),c= matrix[0].size();
        for(int i=0;i<r;i++){
            if(!matrix[i][0])  col0=0;//i found 0th col guy as 0 .
            for(int j=1;j<c;j++){
                
                if(!matrix[i][j])
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        
        
        //Im iterating bottom up so that the moment i reach the upper rows Im already done updating the bottom rows 
        for(int i=r-1;i>-1;i--){
            for(int j=c-1;j>0;j--){
                if( !matrix[i][0] || !matrix[0][j] ) 
                    matrix[i][j]=0;
            }
            if(!col0)matrix[i][0]=0;
        }
    }
};
/*

Don't have to worry too much just update original matric with required changes
Actually time complexity is gonna be m*n but in optimised version space complexity is gonna be constant.

*/