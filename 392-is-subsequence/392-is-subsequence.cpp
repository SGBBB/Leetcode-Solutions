class Solution {
public:
    bool f(string s,string t,int m,int n){
        if(m==0 || n==0)  {    return (m==0)?true:false;}
        if(s[0]==t[0]) {    s=s.substr(1,s.size()-1); m--;}
        return f(s,t.substr(1,t.size()-1),m,n-1);       
    }
    bool isSubsequence(string s, string t) {
        int m=  s.size() ,n=t.size();
        return f(s,t,m,n);
    }
};