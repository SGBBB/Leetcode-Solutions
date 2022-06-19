class Solution {
public:
    int minimumNumbers(int num, int k) {
        // if its empty set then return 0
        if(!num)
            return 0;
        //For every k we have got 10 cases 
        // after 10 th case value is gonna repeat
//         like 9*1=9, 9*11=99 
        
        for(int i=1;i<=10;i++){
            if(i*k>num)
                return -1;
            if( (i*k)%10== num%10 )
                return i;
        }
        /*
        I was unable to get num as exact sum
        
        
        */
        return (-1);
    }
};