class Solution {
public:
    bool divisorGame(int n) {
        //person who endup having 1 is fucked off because he cant choose anything as given 0<choice<n
        //So if Alice endup having 1 so she will left with no choice hence willl lose
        
        if(n>1){
            return !divisorGame(n-1);// the purpose of sing ! is that if any any guy at below level wins the game then this will be a loose for current guy that why i'm inverting the result for current guy
        }
        return false;
    }
};