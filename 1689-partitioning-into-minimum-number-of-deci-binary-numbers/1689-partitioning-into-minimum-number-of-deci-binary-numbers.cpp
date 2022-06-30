class Solution {
public:
    int minPartitions(string n) {
        /*
        
        deci-binary
        
        EMPHASIZE ON THIS STATEMENT:
        return the minimum number of positive deci-binary numbers needed so that they         sum up to n
        
        Think about if the input was only one digit. Then you need to add up as many           ones as the value of this digit.
        
        32 
        
        */
        char ch='0';
        for(auto digit:n)
            ch=max(ch,digit);
        return ch-'0';
    }
};