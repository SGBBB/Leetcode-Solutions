struct node{
    int val,idx;
    node(int val,int idx){
        this->val=val,
        this->idx  =idx;
    }
};
bool cmp(node a,   node b){
    return a.val<b.val;
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalCost=0,n=costs.size()/2;
        vector<node> travelCost; 
        /*
        
        Lets find the cost to travel from A to B which is B-A
        sort this factor in increasing order 
        
        */
        int idx=0;
        for(auto i:costs){
            int cost_a=i[0],cost_b=i[1];
            travelCost.push_back(node(cost_b-cost_a,idx++));
        }
        sort(travelCost.begin() ,travelCost.end() ,cmp);
        for(auto i:travelCost){
            int cost=i.val,
            idx=i.idx;
            if(n-- >0)
                totalCost+=costs[idx][1];
            else 
                totalCost+=costs[idx][0];
        }
        return totalCost;
    }
};

/*
259 + 54  + 667 + 139 + 118 + 469 
54 + 118+139+ 259
ok n people should arrive in each city
got it now.
city a: 259 +   184 + 577 ->1020
city b: 54  +118 + 667  ->      839 
on total it can t be less than  1859.
 How is he auditing values??
 
 How to sort this 2d vector ?
 Allocate every guy in the begining
 10 180  -350 -10
 
 511   -394   -259   -45   -722  -108 
 
 city b: 118   54 
 
 
 */