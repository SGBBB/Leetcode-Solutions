class Solution {
public:
    int climbStairs(int n) {
        int prev2,prev,cur;
        prev2=prev=1;
        if(n<2) return prev2;
        for(int i=2;i<=n;i++){
            cur=prev+prev2;
            prev2=prev;
            prev=cur;
        }
        return cur;
        /*
        0 1 2 3 4
        1 1 2 
        
        */
    }
};