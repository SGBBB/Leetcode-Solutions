class Solution {
    
    
public:
    int minMoves(int target, int maxDoubles) {
        int min_moves=0;
        for(;target>1 and maxDoubles;){
            if(target & 1) target--;
            else maxDoubles--,target/=2 ;
            min_moves++;
            
        }
        return min_moves + target-1;
    }
};