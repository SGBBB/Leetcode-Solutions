class Solution {
public:
    bool checkValidString(string s ,int open_count=0, int close_count=0) {
        if( close_count <0  ) return false;
        int len=s.size() ;
        
        if(len){
            //do some business logic
            
            char ch=s.front();
            s=s.substr(1);
                open_count =(ch=='(')?open_count+1: (ch==')') ?max(open_count-1,0) :max(open_count-1,0)  ,   
                close_count =(ch=='(')?close_count+1:(ch==')')?close_count-1: close_count+1 ;
            return (ch=='(')? checkValidString(s,open_count,close_count) : 
                  (ch==')') ? checkValidString(s,open_count,close_count) :
                    checkValidString(s,open_count,close_count);
            
        }
        return !open_count;
    }
};