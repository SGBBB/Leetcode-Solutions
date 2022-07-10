class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=cost[0],b=cost[1],
        minCost=min({a,b});
        for(int i=2,n=cost.size();i<n;i++){
            minCost=cost[i]+min({a,b});
            a=b,b=minCost;
        }
        
        return min({a,b});
    }
};