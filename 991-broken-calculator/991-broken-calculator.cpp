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
        
        
        */
        if(startValue>=target) return startValue-target;
        int response= (target & 1) ?  brokenCalc(startValue,target+1) :
                brokenCalc(startValue,target/2)   ; 
        return response+1;
    }
};