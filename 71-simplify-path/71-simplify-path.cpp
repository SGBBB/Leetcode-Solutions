class Solution {
public:
    string simplifyPath(string path) {
        if(path.back() !='/' ) path+='/';
        stack<string> st;
        // st.clear();
        string temp="";
        for(char ch:path){
            if(ch!='/' ) temp+=ch;
            if(ch=='/'){
                if( temp=="" or temp=="." ) {
                    //ignore;
                    temp="";
                    continue;
                }
                else if( temp==".."){
                    if(st.size() )st.pop();
                }
                else st.push(temp);
                temp="";//reset temp
            } 
        }
        string ans="";
        for(;st.size() ;  st.pop() ){
            cout<<" stack guys are  "<<st.top() <<endl;
            ans='/' +st.top()  + ans;
        }
        if(ans.empty() ) return "/";
        return ans;
    }
};