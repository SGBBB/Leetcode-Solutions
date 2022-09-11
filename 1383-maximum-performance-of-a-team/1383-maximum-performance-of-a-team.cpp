bool cmp(vector<int> &a,vector<int> &b){
      
    return a[0] >b[0];
}
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> EngineerObj;
        for(int i=0;i<n;i++){
            EngineerObj.push_back({efficiency[i],speed[i]});
        }
        sort(EngineerObj.begin(),EngineerObj.end(),cmp);
        multiset<int> S;
        long speedSum=0,maxPerformance=0;
        //mainitaining heap coresponding to increasing speed
        for(auto it:EngineerObj){
            int curSpeed=it[1],curEfficiency=it[0];
            S.insert(curSpeed);
            speedSum+=curSpeed;
            //if size went greater than k then delete the guy having smallest speed
            if(S.size()>k){
                speedSum-=*S.begin();
                S.erase(S.begin());
            }
            maxPerformance=max({maxPerformance,speedSum*curEfficiency});
        }
        return maxPerformance%(int)(1e9+7);
        
    }
};
/*

2   10  3  1  5  8
5.   4. 3. 9  7. 2    

1 2 5 2 10 3 8 
9 9 7 5 04 3 2

*/