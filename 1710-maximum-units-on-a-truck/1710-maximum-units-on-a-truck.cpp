bool cmp(vector<int> v1,vector<int> v2){
    if(v1[1]!=v2[1])
        return v1[1]>v2[1];
    return v1[0]<v2[0];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // done with sorting 
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int cnt=0;
        for(auto it:boxTypes){
            /*
            
            if truckSize <0 return cnt
            */
            if( truckSize<0 )
                return cnt;
            cnt+= min({truckSize,it[0]})*it[1] ;
            truckSize-=min({truckSize,it[0]});
        }
        return cnt;
    }
};
/*

5*2 + 2*5 + 4*2 + 3*3

*/