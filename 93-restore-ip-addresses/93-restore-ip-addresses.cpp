class Solution {
    vector<string> ipAddresses;
    bool isValidAddress(string str){
        // This is a constant operation becoz at worst case Im checing a string of length 3
        using ll=long long;
        ll digit=stoll(str);
        cout<<str<<endl;
        if( str.size()>3 || digit<0 || digit>255 )
            return false;
        if(str.size()>1 && str[0]=='0')
            return false;
        return true;
    }
public:
    /*
    25525511135
    
    
    255.255.11135
    
    */
    
    void backtrack(string s,int start=0,string temp="",int cnt=4){
        int sz=s.size(); 
        cout<<"temp is -> "<<temp<<" "<<cnt <<endl;
        if(start==sz && !cnt){
            // Now it s avalid IP Address
            temp.pop_back();
            ipAddresses.push_back(temp);
            return ;
        }
        int len=min( { start+3,(int)sz } );
        
        for(int i=start;i< len ;i++){
        //if your current substring is valid then only we trail forward
            
            if( isValidAddress( s.substr(start,i-start+1)  )  ){
                string str=temp + s.substr(start,i-start+1)+'.'  ;
                    
                backtrack(s,i+1,  str ,cnt-1);
                
            }
            
                
        }
        //end of the funciton
    }
    
    vector<string> restoreIpAddresses(string s) {
        //Im using every character present in string ,so longest IP Address can have length 12
        if(s.size()>12) 
            return vector<string>({ });
        backtrack(s);
        return ipAddresses;
    }
};