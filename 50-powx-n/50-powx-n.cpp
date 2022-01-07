class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1.00000;
        double result;
        // if(n &1 )
        double response=myPow(x ,n/2);
        if(  (n &1) ) 
            
            result=(n<0)?(1/x)*response*response:
        (x)*response*response   ;
        else 
            result= response*response ;
            // 1/(response*response);
        
        return result;
    }
};