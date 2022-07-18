class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        /*
        1  -1
        -1  1
        
        */
        int m=matrix.size(),n=matrix[0].size();
        //Doing prefixing
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        
        //checking at every possible indices
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                unordered_map<int, int> counter;
                counter.insert({0,   1 });
                //iterating over all the rows
                int curSum=0;
                for(int k=0;k<m;k++){
                    curSum+=matrix[k][j]-(i>0?matrix[k][i-1]:0);
                    res+=(counter.count(curSum-target)?counter[curSum-target]:0);
                    counter[curSum]++;
                }
                
            }
        }
        
        return res;
    }
};