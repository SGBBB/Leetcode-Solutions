class Solution {
public:
    bool checkValid(vector<vector<int>>& v) {
        int n = v.size();
        if(n<=1) { //edge case
            return true;
        }
        int x=0;
        for(int i=1;i<n+1;i++) x^=i;
        for(int i=0;i<n;i++){
            int row=x,col=x;
            for(int j=0;j<n;j++){
                row^=v[i][j]; //check for cols
                col^=v[j][i]; //check for rows
            }
            if(max(row,col)) return false;
        }
        return true;
    }
};