class Solution {
public:
    int calPoints(vector<string>& ops) {
        //This is a Simple stack problem n 
        int total_record=0;
        stack<int> st;
        for(string ch:ops){
            if(ch=="D") {
                // sure that there is atleast one guy already sitting inside my data structure
                int top=st.top(); 
                top*=2;
                st.push(top);
                total_record+=top;
            }
            else if(ch=="C") total_record-=st.top(),st.pop();
            else if(ch=="+") {
                int top1=st.top();st.pop();
                int top2=st.top();
                st.push(top1);
                st.push(top1+top2);
                total_record+=top1+top2;
            }
            else st.push(stoi(ch)), total_record+=stoi(ch);
        }
        return total_record;
    }
};