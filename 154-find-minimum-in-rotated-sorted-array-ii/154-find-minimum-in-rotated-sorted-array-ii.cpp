class Solution {
public:
    int F(vector<int>& v){
        int l=0,h=v.size()-1;
        while(l<h){
            int m=l+(h-l)/2;
            cout<<v[m]<<endl;
            if(v[m]==v[h]) h--;
            else if(v[m]<v[h] )  h=m; //if im at right range so shrink towards left
            else  l=m+1;
        }
        return v[l];
    }
    int findMin(vector<int>& nums) {
        return F(nums);
    }
};