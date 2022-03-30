class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        if(n==0)
            return false;        
        int low=0,high=(n*m)-1,mid;
        while(low<=high){
            mid=(low+(high-low)/2);
            if(matrix[mid/m][mid%m]==target)
                return true;
            if(matrix[mid/m][mid%m] >target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
        
    }
};