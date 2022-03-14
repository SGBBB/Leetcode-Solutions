class Solution {
public:
    int findMin(vector<int>& v) {
        int l=0,h=v.size()-1;
        while(l<h){
            int m=l+(h-l)/2;
            if(v[m]<=v[h]) h=m;
            else l=m+1;
        }
        return v[h];
    }
};