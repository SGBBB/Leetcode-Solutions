class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='(') {
                st.push(i);
            }
            else if (ch==')'){
                if(st.size() and s[st.top() ] =='(') st.pop();
                else st.push(i);
            }
            
        }
        cout<<st.size()<<endl;
        while(!st.empty()){
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};