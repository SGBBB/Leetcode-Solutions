class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string A,B;
        for(char ch:s){
            if(ch=='#'){
                if(A.size()) {A.pop_back(); }
                else continue;
            }
            else  A.push_back(ch);    
            
        }
        
        for(char ch:t){
            if(ch=='#'){
                if(B.size()) {B.pop_back(); }
                else continue;
            }
            else
            B.push_back(ch);            
        }
        return A==B;
    }
};