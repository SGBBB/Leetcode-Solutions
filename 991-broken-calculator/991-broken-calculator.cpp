class Solution {
public:
    int brokenCalc(int startValue, int target) {
        /*
        Should I think in reverse manner?
        like start from target then gradually loose value until i reach start value
        can't use recursion here
        A thing to ponder is that-> while moving down, I cant risk to take my target below start 
        
        hint to emphasise on: ""If y is even, the last move was multiplication, else decrement" So true!"
        
        
        
        test for the following test cases:
        * 3 19
        
        while going back to the startValue
        i'm eleiminating the huge values  by just half 
        So time complexity turns out to be log(target).
        
        */
        if(startValue>=target) return startValue-target;
        /* 
        if the number is odd then add 1 to it to make it even 
        
        */
        return 1+((target & 1) ?  brokenCalc(startValue,target+1) :
                  
                brokenCalc(startValue,target/2) )  ; 
        
    }
};