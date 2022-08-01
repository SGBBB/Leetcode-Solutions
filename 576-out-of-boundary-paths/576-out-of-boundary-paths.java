int dp[51][51][51]={};
int directions[]={-1,0,1,0,-1};
class Solution {
    int m,n;
    int dfs(int r,int c,int maxMove){
        int curMoveCnt=0;
        //if we are movbing out of bounds then return 1 it will be counted as a step
        if( min({r,c})<0 || r>m-1 || c>n-1 ){
                    return 1;           
        }
        if(dp[r][c][maxMove]>-1)
            return dp[r][c][maxMove];
        //if maxMove>0:
        //else if left with no moves then simply return 0.
        if(maxMove>0){
            
            
            for(int k=0;k<4;k++){
                int newi=r+directions[k],
                    newj=c+directions[k+1];
                
                    
                //collecting moves returned by child function calls
                curMoveCnt+=dfs(newi,newj,maxMove-1) % 1000000007;
                curMoveCnt=curMoveCnt%1000000007;
            }
            
        }
        return dp[r][c][maxMove]=curMoveCnt;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m=m,
        this->n=n;
        memset(dp,-1,sizeof dp);
        return dfs(startRow,startColumn,maxMove);
    }
};