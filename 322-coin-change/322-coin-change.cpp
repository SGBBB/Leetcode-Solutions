// long len=2*(1e31)-1;
// long dp[ 1000 1 ]={};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount,int cnt=0) {
        
//         if(!amount){
//             return cnt;
//         }
//         if(amount<0){
//             return INT_MAX-1;
//         }
//         long minAmount=INT_MAX-1;
        
            
//         for(auto it:coins){
//             if(it>amount) break;
//             long tempAns=coinChange(coins,amount-it,cnt+1);
//             cout<<tempAns<<endl;
//             minAmount=
//                 min(minAmount, tempAns);
//         }
//         return minAmount==INT_MAX-1 ?-1 : minAmount;
        if(!amount)
            return 0;
        queue<vector<long>> q;
        set<long> S;
        
        for(auto it:coins){
            if(   it>amount )
                continue;
            q.push({it,1}),
            S.insert(it);
        }
        
        /*
        steps 1: 1 2 5 
        steps 2: 3 6 4 7 10
        steps 3: 8 11
        
        
        
        */ 
            
        while( !q.empty() ){
            long val = q.front()[0] ,
            steps=q.front()[1];
            q.pop();
            if(val==amount)
                return steps;
            for(auto it:coins){
                if( S.count(val+it) || val+it>amount )
                    continue;
                q.push({val+it,steps+1});
                S.insert(val+it);
            }
        }
        return -1;
    }
};