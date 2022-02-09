class Solution {
    string helper(int& pos, string s) {
        int num=0,len=s.size();
        string str = "";
        for(;pos<len;pos++){
            cout<<num<<endl;
            char ch=s[pos];
            if(ch=='['){
                pos++;
                string temp=helper(pos,s) ;
                // cout<<temp<<endl;
                while(num--) {str+=temp;}
                num=0;
                // cout << " temp "<<str<<endl;
            }
            else if(ch==']') return str;
            else if( isdigit(ch)  ) num=(num*10) + (ch-'0');
            else str+=ch;
        }
        cout<<"str is "<<str<<endl;
        return str;
    }
    public:
    string decodeString(string s) {
        int pos = 0;
        return helper(pos, s);
    }
    
    

};