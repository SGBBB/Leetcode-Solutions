int dp[50][50];
vector<int> vals;
class Solution {
    int calScore(int i,int j){
        //Base Case
        if( j-i+1 <3 ) return  dp[i][j]= 0;  //if your length is less than 3 so rreturn 0 contribution by this side;
    if(dp[i][j]!=-1) return dp[i][j];
        int minCost=INT_MAX;
        for(int  k=i+1;k<j;k++){
            int curCost=vals[i]*vals[k]*vals[j];
            minCost=min(minCost,calScore(i,k)+curCost+calScore(k,j));
        }
        return dp[i][j]=minCost;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        vals=values;
        memset(dp,-1,sizeof dp);
        return calScore(0,values.size()-1);
        // return dp[ ][];
    }
};
/*




You just need to sense that this problem belongs to partition dp 
if you did this then problem is just cakewalk for you
You need to think where to place partition(k) then this problem is just cakewalk.
For every placing of k you need to cimpute ans 
Finally among all such ans we need to find the minimum.
Try to solve this problem while considering smaller sub-problem eventually its gonna solve larger sub problem levels.


*/