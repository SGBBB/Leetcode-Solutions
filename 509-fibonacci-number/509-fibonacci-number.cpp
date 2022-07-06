class Solution {
public:
    int fib(int n) {
        int prev=0,cur=1,sum=0;
         /*
         
         0 1 1 2 3
         
         */
        if(n<2)
            return n;
        for(int i=2;i<=n;i++){
            
            sum=prev+cur;
            //updating vallirables
            prev=cur,
            cur=sum;
            
        }
        return sum;
    }
};