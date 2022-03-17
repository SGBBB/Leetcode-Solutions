class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char ch:s){
            if(ch=='(') st.push(0);
            else{
                int temp=st.top();
                st.pop();
                int val=0;
                if(temp) {
                    val=2*temp;
                }
                else val=1;
                
                st.top()= st.top()+val;
            }
        }
        return st.top();
    }
};