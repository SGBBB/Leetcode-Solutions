class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<int,int> M;
        for(auto it:num)
            M[it]++;
        string ans="";
        char singleFreqChar='*';
        //1. Scan through whole string 
        for(char ch='9';ch>='0';ch--){
            int cnt=M[ch];
            if( ch=='0'  ){
                //if u. hhave not got size and singleFreqChar=='*' then return "0";
                if( !ans.size() && singleFreqChar=='*')
                    return string(1,'0');
                else if(!ans.size() && singleFreqChar!='*')
                    return string(1,singleFreqChar);
                 
            }
            // Now, if I met ch=='0' then I have got ans.size 
            //capture the highest char having odd freq This will executre only once
            if( singleFreqChar=='*' && (M[ch]&1) )
                singleFreqChar=ch;
            ans+=string(cnt/2,ch);
            
        }
        string remainingString;
        //if I have got singleFreqChar 
        if(singleFreqChar!='*'){
            //2. append 2nd part to ans
            ans+=singleFreqChar;
            remainingString=ans.size()>0?ans.substr(0,ans.size()-1):"";
        }
        else{
            remainingString=ans.size()>0?ans.substr(0,ans.size()):"";
        }
        
        
        //reverse 3rd part
        reverse(remainingString.begin(),remainingString.end());
        //append third part to ans
        ans+=remainingString;
        return ans;
    }
};