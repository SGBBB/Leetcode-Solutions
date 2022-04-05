class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        /*
        Let me use recursion to crack this problem
        
        */
        if(target>1){
            
            return (
                
(!maxDoubles) ?  target-1 :
              
( target&1 )  ?
    minMoves(target-1,maxDoubles)+1: 
                minMoves(target/2,maxDoubles-1)+1
          //here im doing +1   so that contribution current step is also considered  while returning back to parent function call     
                    );
        }
        return 0;//ok fine now you reached to 1 just return 0 which means no more moves are needed
    }
};