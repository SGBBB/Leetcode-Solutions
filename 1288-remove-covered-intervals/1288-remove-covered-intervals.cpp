bool cmp(vector<int> a,vector<int> b){
    return (a[0]!=b[0]) ? a[0]<b[0]:a[1]>b[1] ;
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end() ,cmp );
        int n=intervals.size(),prev_start=-1,prev_end=-1,cnt=0;
        for(auto i:intervals ){cout<<i[0] << i[1]<<endl;
            if(i[1]>prev_end) cnt++,prev_end=i[1];
            
        }
        return cnt;
    }
};

/*
1 4
2 8
3 6


*/