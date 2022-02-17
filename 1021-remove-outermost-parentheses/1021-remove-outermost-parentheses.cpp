class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int open=0 , n=s.size() ;
        for(int i=0;i<n;i++){            
            if(s[i]=='(')  {
                if( open>0) res+=s[i];
                open++;
            }
            
            else {
                if(open>1) res+=s[i];//it must be greater than 1 becoz apne paas ek open hona zaruri hai
                open--;
            }
            
            
        }
        return  res;
    }
};