class Solution {
    /*

1  5   9 
10 11  13
12 13  15


1  15 
10 21

lessThanEqual();
        


*/
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int n=matrix.size(),m=n;
        int cnt = 0, c = n - 1; // start with the rightmost column
        for (int r = 0; r < m; ++r) {
            while (c >= 0 && matrix[r][c] > x) --c;  // decrease column until matrix[r][c] <= x
            cnt += (c + 1);
        }
        return cnt;
    }
    // int lessThanEqual(vector<vector<int>>& matrix,int target){
    //     int n=matrix.size(),cnt=0,i=0,j=n-1;
    //     while(i<n-1 && j>0 ){
    //         if(matrix[i][j]<=target){
    //             cnt+=j+1;
    //             i++;
    //         }
    //         else{
    //            j--; 
    //         }
    //     }
    //     return cnt;
    // }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int lowNum=matrix[0][0], highNum= matrix[n-1][n-1];
        int bestAns ;
        while(lowNum<=highNum){
            int midNum=lowNum+(highNum-lowNum)/2;
            int res=countLessOrEqual(matrix,midNum);
            if(res>=k){
                highNum=midNum-1;
                
                bestAns=midNum;
                cout<<" bestAns "<<bestAns<< " "<<res<<" "<<midNum <<endl;
            }
            else{
                lowNum=midNum+1;
            }
        }
        return  bestAns;
    }
};

