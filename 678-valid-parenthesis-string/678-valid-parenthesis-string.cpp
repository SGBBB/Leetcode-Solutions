class Solution {
public:
    bool checkValidString(string s ,int open_count=0, int close_count=0) {
        int cmin=0,cmax=0;
        // Im damn sure my ans is gonna lie btw cmin and cmax
         for(char ch:s){
             if(ch=='('){
                 cmin++,cmax++;
             }
             else if(ch==')'){
                 cmin--,cmax--;
             }
             else{
                 cmin--,cmax++;
             }
             if(cmax<0) {
                 //  Currently, don't have enough open parentheses to match close parentheses-> Invalid
                 return 0;
             }
             cmin=max(cmin,0);
         }
        return !cmin;//just checking whether there is sime balanced parenthesis or not
    }
};