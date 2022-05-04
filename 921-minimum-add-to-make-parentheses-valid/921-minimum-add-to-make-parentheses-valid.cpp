class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;
        for(auto ch:s) {
            if(ch=='(') open++;
            else {
                if(!open) close++; //if there are no opening parenthesis then add right parenthesis
                else open--;} //if there are some open parenthesis then decrement open becoz these are valid parenthesis
        }
        return open+close;
    }
};

/*
))) () )) ((( )
as soon as i get open so incrementopen else decrement but if open is 0 then what??
open=1
ans=1
*/