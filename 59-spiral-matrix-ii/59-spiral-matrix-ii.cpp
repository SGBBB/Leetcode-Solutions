class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int r1=0,r2=n-1;
        int c1=0,c2=n-1;
        int val=1;
        vector<vector<int>>ans(n,vector<int>(n));
        while(r1<=r2 && c1<=c2){
            //iterate from left to right
            for(int i=c1;i<=c2;i++)
                ans[r1][i]=val++;
            //iterating forom up to down
            for(int i=r1+1;i<=r2;i++)
                ans[i][c2]=val++;
            //iterating from bottom-right to bottom-left
            for(int i=c2-1;i>=c1;i--)
                {cout<<" came inside "<<endl; ans[r2][i]=val++;}
            //iterating from bottom to up
            for(int i=r2-1;i>r1;i--)
                ans[i][c1]=val++;
            c1++,
            r1++,
            c2--,
            r2--;
        }
        return ans;
    }
};