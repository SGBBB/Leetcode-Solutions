class Solution {
public:
    bool isPowerOfFour(int n) {
        /*
        4   00100
        16  10000
        32  1000000
        
        */
        for(int i=0;i<32;i+=2){
            if(1<<i == n)
                return 1;
        }
        return 0;
    }
};