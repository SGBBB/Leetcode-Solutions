class Solution {
public:
    string smallestNumber(string pattern) {
        
        /*
        n+1 these any digits i need to consider
        IIIDIDDD
        123549876
        
        ididi
        162534
        
        idi
        1324
        
        1234
        
        di
        213
        123
        
        
        iiiiddi
        12347658
        12347856
        
        
        iidiiddi
        128347659
        128347659
        
        diidi
        123456
        312.3.
        
        
        ddidi
        123456
        321.2
        
        
        ddiii
        123456
        321456
        
        
        ddiiidd
        12345678
        32145876
        
        */
        int n=pattern.size();
        string ans(n+1,'0');
        stack<int> st;//stack to kep track of indices having ch='D'
        int num='1';
        for(int i=0;i<=n;i++){
            
            if(pattern[i]=='I' || i==n){
                ans[i]=num,
                num++;
                while(!st.empty()){
                    ans[st.top()]=num,
                    num++;
                    st.pop();
                }
            }
            else{
                st.push(i);
            }
        }
        return ans;
    }
};