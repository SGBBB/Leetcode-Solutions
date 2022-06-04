using ll=long long ;
class Solution {
    
    bool backtrack(string &s,int start=0, ll prevNumber=0){
        
        int n=s.size();
        if(start==n){
            return true;
        }
        
        int len= !start ? n-1 : n ;
        for(int idx=start;idx<len;idx++){
            
            ll curNumber=stoll(s.substr(start,idx-start+1));
            if(curNumber>=1e11 )return 0;
            if( !start ||  prevNumber - curNumber==1 ){
                // cout<<start<<" "<<idx<<" "<<prevNumber<<" "<<curNumber<<endl;
                bool response=backtrack(s,idx+1,curNumber);
                if(response)
                    return true;
                
            }
            
            
            // Let's remove leading zeroes
            
        }
        
        return false;
    }
public:
    bool splitString(string s) {
        return backtrack(s );
    }
};